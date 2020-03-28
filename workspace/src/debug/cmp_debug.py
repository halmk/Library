import random
import os
import sys
import subprocess
import re
import time
import string

## パイプの形でコマンドを実行する
##   引数 cmd: コマンド文字列（オプションを含んでもよい）
##   引数 text: 入力の文字列
##   返り値: 出力結果の各行から成る配列
## ※入力文字列，出力文字列は全て UTF-8 化されているものとする
def run_command_in_pipe(cmd, text):
    # プロセスを生成：
    # - 標準入力から解析対象の文字列を受け取る
    # - 解析結果を標準出力に返す
    proc = subprocess.Popen(cmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE)

    # プロセスの入出力はバイト列で行うので，プロセスにデータを渡す際には文字列をバイト列に
    # 変換(encode）し，プロセスからデータを受け取る際にはバイト列を文字列に変換(decode)する
    # （その際に文字コードを指定する）
    result = proc.communicate(text.encode("utf-8"))[0].decode("utf-8")

    # 出力結果を行単位に分割して配列に詰める
    lines = []
    for line in re.split("[\r\n]+", result):
        lines.append(line)

    # 配列を返す
    return lines

def randomname(n):
   return ''.join(random.choices(string.ascii_letters, k=n))

# メインの処理
if __name__ == '__main__':
    # テストしたいファイルと愚直解法のファイルをコンパイル
    run_command_in_pipe('g++ source.cpp -o source.out', "")
    run_command_in_pipe('g++ honesty.cpp -o honesty.out', "")

    cnt = 0
    # WAになるまでループ
    while True:
        print('\n'+f'----- test: {cnt} -----')
        cnt += 1

        # 入力フォーマットに合わせてケースを生成する (生成したいフォーマットを別モジュールからimportしたい..)
        input = ""
        '''
        n_lim = [900000,1000000]
        n = random.randint(n_lim[0],n_lim[1])
        print(n)
        input += str(n) + '\n'
        lst = list(range(1,1000000))
        a_list = random.sample(lst, n)

        a_list.sort()
        #print(" ".join(map(str,a_list)))
        input += " ".join(map(str,a_list))
        print()
        '''
        n_lim = [1, 1000]
        n = random.randint(n_lim[0], n_lim[1])
        #input += str(n) + '\n'
        #print(str(n))
        range_lim = [1, 1000]
        for _ in range(n):
            a = random.randint(range_lim[0],range_lim[1])
            input += f'{a} '

        input += '\n'

        for _ in range(n):
            b = random.randint(range_lim[0],range_lim[1])
            input += f'{b} '

        input += '\n'

        #print(input)
        # 生成したケースを標準入力として実行する.
        main_start = time.time()
        main_result = run_command_in_pipe('./source', input)
        main_end = time.time()
        print(f'source: {(main_end-main_start)*1000:.2f}ms')
        print('source: ', main_result)

        honesty_start = time.time()
        honesty_result = run_command_in_pipe('./stupid', input)
        honesty_end = time.time()
        print(f'stupid: {(honesty_end-honesty_start)*1000:.2f}ms')
        print('stupid: ', honesty_result)

        # 結果の長さが違うなら,WA
        if len(main_result) != len(honesty_result):
            break

        # 出力結果を比較する
        for main_out, honesty_out in zip(main_result, honesty_result):
            # 結果が違うなら,WA
            if main_out != honesty_out:
                break
        else:
            print('OK.')
            #break
            continue
        # WA が見つかったら中断
        break