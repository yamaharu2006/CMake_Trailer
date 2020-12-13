# Visual Studio Code から Docker のビルドを可能にしよう

# 使い方
1. CMake_Trailer を Dockerマシン上にクローン

2. 

3. Visual Studio Code の 拡張機能 Remote - SSH を使用してDockerのコンテナに接続する

4. ワークスペースを開く
    Visual Studio Code から
    /CMake_Trailer/.vscode/workspace.code-workspace を開く

# 困ったときに
Q. ファイルを追加したら、ビルドできなくなった(インクルードパスが通らなくなった)
    コマンドパレットから CMake のキャッシュ削除と再構築 を行う

Q. デバッグ実行をしても古いコードが実行される
    デバッグ実行(F5)をしただけでは再ビルドされません。再ビルド(F7)してください。
