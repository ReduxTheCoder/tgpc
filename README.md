<h1 align="center">
<img src="assets/tgpc_logo.png" width="600">
</h1><br>
TGPC is a C command-line tool to quickly scaffold code projects using templates.

## Features
- Quickly create projects
- Compile/Run them

## Project Status
TGPC currently lacks lots of his barebones features, as it's still in development:
- Windows support
- Commands
- Additional language support

New features will be added in future releases

## Installation
First clone the repository and then build using the makefile:
```bash
git clone https://github.com/ReduxTheCoder/tgpc
cd tgpc
make build
```
Optionally you can remove the cloned repository:
```bash
cd ..
rm -r tgpc
```

You can also directly download the binary from our releases, and move it in your PATH variable

## Quick start
to display a help message that shows all commands:
```bash
tgpc help
```

to create a project with a name and a language:
```bash
tgpc new "my-project" "py"
```

## Language Support
here's a table showing supported languages and their respective name to use:
| Language   | tgpc |
| ---------- | ---- |
| Python     | py   |
| C          | c    |
| C++        | cpp  |
| Java       | java |
| Rust       | rs   |
| Assembly   | asm  |
| JavaScript | js   |
| TypeScript | ts   |
| Ruby       | rb   |
| Golang     | go   |
| PHP        | php  |

## OS Support
Currently, TGPC supports:
- Linux
- macOS

Windows support may be added in a future release
