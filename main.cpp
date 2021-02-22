#include <iostream>

char shift (char symb, int key, char a, char z) {
  if ((symb + key) > z) {     
    symb += key - z + a - 1;
  } else if ((symb + key) < a) {
    symb += key + z - a + 1;
  }
  else {
    symb += key;
  }
  return symb;
}

// Шифровщик
std::string encryptCaesar (std::string str, int key)
{
  bool isLower;
  bool isUpper;
  for (int i = 0 ; i < str.length(); i++) {
    isLower = str[i] >= 'a' && str[i] <='z';
    isUpper = str[i] >= 'A' && str[i] <='Z';
    if (isLower) {
       str[i] = shift(str[i], key, 'a', 'z');   
    } else if (isUpper) {
      str[i] = shift(str[i], key, 'A', 'Z');  
    }
  }
  return str;
}

// Дешифровщик
std::string decryptCaesar(std::string str, int key) {
  return encryptCaesar(str, key * -1);
}

int main() {
  //std::cout << char('a' + 5);
  std::string s;
  int key, answer;
  std::cout << "Введите строку: ";
  std::getline(std::cin, s);
  std::cout << "Введите ключ: ";
  std::cin >> key;

  std::cout << "1 - Шифровщик\n" 
            << "2 - Дешифровщик\n";

  std::cout << "Действие: ";
  std::cin >> answer;
  if (answer == 1){
    std::cout << encryptCaesar(s, key);
  } else if ( answer == 2){
    std::cout << decryptCaesar(s, key);
  } else {
    std::cout << "Error!";
  }
}

/*
Шифр Цезаря
В древности для зашифрования сообщений использовался такой способ. Все буквы в сообщении сдвигались на одно и то же число позиций в алфавите. Число позиций могло быть как положительным, так и отрицательным, и являлось параметром шифра. Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается (то есть буква с номером 27 - это снова a, буква с номером 28 - это b, и так далее). Например, слово abracadabra при сдвиге на 10 позиций превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно. Напишите функцию encryptCaesar от строки и числа, которая возвращает исходную строку, зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decryptCaesar, выполняющую обратное преобразование. Считаем, что входные строки состоят лишь из английских букв; если там содержатся и другие символы, то их надо игнорировать.

Подсказка: имея функцию encryptCaesar, функцию decryptCaesar можно реализовать в одну строчку.

Пример 1:
The quick brown fox jumps over the lazy dog
5

Пример 2:
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
25
*/