extern crate jsonway;
extern crate serde_json;
extern crate serde;

use std::fs::File;
use std::env;
use std::path::Path;
use std::io::prelude::*;
use std::collections::HashSet;

#[derive(Debug)]
struct Snippet {
    name: String,
    prefix: String,
    body: Vec<String>,
    description: String
}

// Recursive library file search
fn rec_file_search(path: String, mut files: &mut HashSet<String>) {
    let path = Path::new(&path);
    for entry in path.read_dir().unwrap() {
        if let Ok(entry) = entry {
            if entry.path().is_file() { files.insert(entry.path().to_str().unwrap().to_string()); }
            else { rec_file_search(entry.path().to_str().unwrap().to_string(), &mut files); }
        }
    }
}

fn main() {
    // Get current path
    let path = env::current_dir().unwrap();
    println!("starting dir: {}", path.display());

    // Change dir to library in cpp
    let library_path = String::from(path.parent().unwrap().to_str().unwrap()) + "/library/cpp";
    println!("current dir: {}", library_path);

    // Get file paths in library dir
    let mut file_paths = HashSet::new();
    rec_file_search(library_path, &mut file_paths);

    let mut snippets:Vec<Snippet> = Vec::new();

    // Read file paths in library dir
    for file_path in file_paths {
        let file_path = Path::new(&file_path);
        // Extract function name
        let name = file_path.file_stem().unwrap().to_str().unwrap().to_string();
        let prefix = name.clone();
        let description = name.clone();
        println!("name: {}", name);

        // Read file
        let mut file = File::open(&file_path).expect("Error file open");

        // Get contents of the file
        let mut contents = String::new();
        file.read_to_string(&mut contents).unwrap();
        //println!("{:?} contents:\n{}", file_path, contents);

        // Extract snippet part
        let mut body = vec![];
        let rows:Vec<_> = contents.split("\r\n").collect();
        let mut flag = false;
        for row in rows {
            if row == "/* snippet part end */" { break; }
            if flag { body.push(row.to_string()); }
            //println!("{}", row);
            if row == "/* snippet part start */" { flag = true; }
        }

        // Create Snippet instance
        let snippet = Snippet {
            name, prefix, body, description
        };
        //println!("{:?}", snippet);
        snippets.push(snippet);
    }

    // Serialize to JSON format
    let json = jsonway::object(|json| {
        for snippet in snippets {
            let Snippet{name, prefix, body, description} = snippet;
            json.object(name, |json| {
                json.set("prefix", prefix);
                json.array("body", |json| {
                    for row in body {
                        json.push(row);
                    }
                });
                json.set("description", description);
            });
        }
    }).unwrap();

    println!("{}", json);

    // Write in json file
    let mut file = File::create("snippet.json").unwrap();
    file.write_all(serde_json::to_string(&json).unwrap().as_bytes());

}
