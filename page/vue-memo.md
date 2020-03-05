# vue-cli+GithubPagesでWebサイトを公開

## vue-cliのインストール

```
$ npm install -g vue-cli
```



## vue-cliでプロジェクトの作成

- vue init コマンドで作成する

```
$ vue init <template-name> <project-name>
```

- templateはいくつかある
  - webpack
  - webpack-simple
  - browserify
  - browserify-simple
  - pwa
  - simple
- 今回は`webpack`を採用する

```
$ vue init webpack my-project
```

- 色々質問されるが、適当に答える。基本的には`Yes`でOK

- 開発サーバの立ち上げ

```
$ cd my-project
$ npm install
$ npm run dev
```

- `http://localhost:8080/`にアクセスできることを確認



## vue-cliでのリリースの準備

- リリースのためのビルドを行う前に。

- デフォルトでは、`my-project/dist/`にビルドされたファイルが配置される
- GithubPagesに対応するように設定ファイルを変更する
  - `index.html`は `https://{ドメイン}/{リポジトリ名}/docs/index.html`に置かれる
  - jsやcssは `https://{ドメイン}/{リポジトリ名}/docs/static/~`に置かれるため、この状態では、`index.html`から静的ファイルが取得できない
  - ここで、`config/index.js`を書き換えることで対策する
    - `dist`を`docs`に変更(2箇所)
    - `build`オブジェクト内の`assetsPublicPath`を変更する
    - staticファイルのパスは`assetsPublicPath`と`assetsSubDirectory`を連結されてパスを構成しているので、`assetsPublicPath`を`./`にすることで、相対パスにすることができる
    - `assetsPublicPath: '/'` → `assetsPublicPath: './'`
- ビルドする

```
$ mkdir docs
$ npm run build
```

- リポジトリにいつもどおりプッシュする





## Githubでデプロイ設定

- SettingsからSourceを `master branch /docs folder`にする
- `https://{ドメイン}/{レポジトリ名}/`でデプロイされていることを確認する























