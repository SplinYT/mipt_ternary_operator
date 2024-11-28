#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

void ReplaceSpace(std::string& str) {
  size_t pos = 0;
  while ((pos = str.find("  ", pos)) != std::string::npos) {
    str.replace(pos, 2, " ");
  }
}

void Process(const std::string& filename) {
  std::ifstream input_file(filename);
  if (!input_file.is_open()) {
    std::cerr << "[МФТИ] Ошибка при чтении файла, укажи его по-человечески!" << std::endl;
    return;
  }

  std::stringstream buffer;
  buffer << input_file.rdbuf();
  input_file.close();

  std::string code = buffer.str();

  size_t if_pos = code.find("if");
  while (if_pos != std::string::npos) {
    size_t open_paren = code.find("(", if_pos);
    size_t close_paren = code.find(")", open_paren);
    std::string condition = code.substr(open_paren + 1, close_paren - open_paren - 1);

    size_t open_brace = code.find("{", close_paren);
    size_t close_brace = code.find("}", open_brace);
    std::string if_block = code.substr(open_brace + 1, close_brace - open_brace - 1);

    std::replace(if_block.begin(), if_block.end(), '\n', ' ');
    std::replace(if_block.begin(), if_block.end(), '\r', ' ');
    std::remove(if_block.begin(), if_block.end(), ';');
    ReplaceSpace(if_block);

    size_t else_pos = code.find("else", close_brace);
    std::string else_block = "";
    if (else_pos != std::string::npos) {
      open_brace = code.find("{", else_pos);
      close_brace = code.find("}", open_brace);

      if (open_brace != std::string::npos && close_brace != std::string::npos) {
        else_block = code.substr(open_brace + 1, close_brace - open_brace - 1);
      }

      std::replace(else_block.begin(), else_block.end(), '\n', ' ');
      std::replace(else_block.begin(), else_block.end(), '\r', ' ');
      std::remove(else_block.begin(), else_block.end(), ';');
      ReplaceSpace(else_block);
    }

    if (else_block == "") {
        else_block = "0";
    }

    std::string ternary_expr = condition + " ? (" + if_block + ") : (" + else_block + ");";
    code.replace(if_pos, close_brace - if_pos + 1, ternary_expr);

    if_pos = code.find("if", if_pos + ternary_expr.length());
  }

  std::ofstream output_file(filename, std::ios::trunc);
  if (!output_file.is_open()) {
    std::cerr << "[МФТИ] Ошибка при чтении файла, укажи его по-человечески!" << std::endl;
    return;
  }

  output_file << code;
  output_file.close();

  std::cout << "[МФТИ] Файл успешно обновлен. Условный оператор заменен на тернарный!))))" << std::endl;
}

int main() {
  std::cout << R"(
  ███       ███         ██████       ████████████     ██         ███
  ██ ██   ██ ██       ██  ██  ██          ██          ██       ██ ██
  ██  ██ ██  ██     ██    ██    ██        ██          ██      ██  ██
  ██    █    ██     ██    ██    ██        ██          ██     ██   ██
  ██         ██       ██  ██  ██          ██          ██    ██    ██
  ██         ██         ██████            ██          ██   ██     ██
  ██         ██           ██              ██          ██  ██      ██
  ██         ██           ██              ██          ██ ██       ██
  ██         ██           ██              ██          ███         ██

  МФТИ - Московский физико-технический институт
  )" << std::endl;
  std::string filename;
  std::cout << "[МФТИ] Введите название файла: ";
  std::cin >> filename;

  Process(filename);

  return 0;
}