Введение.

Актуальность и современность темы: Большое количество программистов ежедневно используют условные операторы при написании программ на различных языках программирования. Многие из них при написании своего кода переводят их в тернарные операторы, которые позволяют сократить объем кода и сделать его более компактным. Автоматизация этого рутинного процесса позволит сократить время на написание кода, чем повысит эффективность работы с кодом.
Цель работы: Целью данного проекта является написание программы для автоматического перевода условных операторов в тернарные операторы в коде на языке программирования C++.
Задачи:
1.	Изучить структуру условных и тернарных операторов для перевода из одного в другой.
2.	Проанализировать асимптотику и выявить самый эффективный подход для решения данной задачи.
3.	Рассмотреть возможные вариации использования условных операторов для корректного перевода в тернарный оператор.
4.	Изучить библиотеки, необходимые для обработки кода и обновления файла с результатом.
5.	Написать программу на языке программирования C++ для реализации поставленных задач.
Содержание проекта: Структура проекта предусматривает наличие введения, четырех глав и заключения. Каждая глава рассматривает определённый аспект работы программы и ее компонентов, предлагая читателю подробный анализ. Работа завершается обобщением полученных данных и формулированием выводов по исследованной теме.
Значимость темы: Значимость изучения перевода условного оператора в тернарный для автоматизации.
В рамках данного проекта мы подробно рассмотрим и реализуем программу для перевода условных операторов в тернарные операторы на языке программирования C++.

1. Использование условных и тернарных операторов
1.1 Условные операторы с условием без альтернативной ветви
Довольно часто программисты при работе с языком программирования C++ сталкиваются с необходимостью выполнять часть кода при соблюдении некоторых условий. Самым простейшим является использование условного оператора без альтернативной ветки (далее «else»). Мы привели пример такого кода в программе Visual Studio Code:
![image](https://github.com/user-attachments/assets/a99b96e5-30d0-419b-b817-7b5b822c6969)

 
	Конструкция тернарного оператора с аналогичным условием и внутренним кодом будет выглядеть так:
![image](https://github.com/user-attachments/assets/e1e88a3c-a47e-4d66-bd6f-e6b2ee651fb3)

 
	Значит для использования такого подхода, наша программа должна заменять блок «else» на число 0, а также удалять символ «;» из конца строки кода, выполняющегося при выполнении соответствующего условия.
Перевод такого кода будет осуществляться по следующему алгоритму:
условие ? (код при выполнении условия) ∶(0);

1.2 Условные операторы с условием и альтернативной ветвью
	Подход с совместным использованием оператора с условием и наличием альтернативной ветви требует обрабатывать отдельно блок «if» и «else». Мы привели пример такого кода в программе Visual Studio Code:
![image](https://github.com/user-attachments/assets/293a7bd8-7b6d-488d-bf4f-659053a2149e)

 
Конструкция тернарного оператора с аналогичным условием и внутренним кодом будет выглядеть так:
![image](https://github.com/user-attachments/assets/4ea7e191-1b53-48db-9601-523847f2a02f)

 
В данной ситуации мы преобразуем код в формат:
условие ? (код при выполнении условия) ∶(код альтернативной ветви);

1.3 Условные операторы с несколькими условиями
В практике мы сталкиваемся с несколькими условиями в условном и тернарных операторах. Условий может быть несколько, а может быть и целое множество в зависимости от вида задач, которые мы ставим перед собой. Рассмотрим данный код:
![image](https://github.com/user-attachments/assets/ee948e58-8466-404c-8186-ca6378fc6b43)

 
В таком коде используется двойное условие. Переменная x должна быть больше переменной y, а также переменная y больше 1. В таком случае тернарный оператор будет выглядеть так:
![image](https://github.com/user-attachments/assets/3f02ae9b-6731-467e-85d6-d762a09596ba)

 
При формировании такого кода мы будем использовать тот же подход, как и с условными операторами с условием и альтернативной ветвью с важным замечанием – оба логических выражения будут находиться в условии:
условие ? (код при выполнении условия) ∶(код альтернативной ветви);

2. Чтение и обработка входного файла
Для того, чтобы код программы, в которой мы хотим заменить условный оператор на тернарный, был открыт и переведен в строковый формат, мы использовали библиотеки fstream и sstream. Они позволяют работать с файлами, открывать, читать и записывать данные в них. Благодаря библиотеке sstream мы можем работать с потоками строк для удобного хранения содержимого файла в строке.
![image](https://github.com/user-attachments/assets/b251865a-40b5-4455-9fb1-3c407503eeec)

 
Функция Process выполняет чтение содержимого текстового файла и сохраняет его в строковую переменную для дальнейшей обработки. В начале работы создается объект std::ifstream. Если файл не удается открыть (например, он не существует или его невозможно прочитать), функция выводит сообщение об ошибке и завершает выполнение. Это предотвращает дальнейшие попытки работы с несуществующим или недоступным файлом.
Если файл успешно открыт, данные из него считываются в объект std::stringstream, который служит буфером для временного хранения прочитанного содержимого. Для этого используется метод rdbuf(), который копирует данные из потока файла в поток строки. Этот подход позволяет полностью считать данные файла, независимо от его размера, и обработать их как строку.
После того как данные были успешно считаны в буфер, файл закрывается с помощью метода close(), что освобождает ресурсы, связанные с потоком.
В конце содержимое потока строки извлекается с помощью метода str(), и результат сохраняется в строковой переменной. Таким образом, весь текст из файла оказывается доступным в виде строки, с которой можно продолжать работать в программе. 
![image](https://github.com/user-attachments/assets/00f72cd7-f60e-41c9-9340-273eabde0eaa)

 
Этот код выполняет запись данных в файл. Сначала создается объект std::ofstream, который представляет поток вывода, предназначенный для записи в файл. При этом файл открывается с флагом std::ios::trunc, что означает, что если файл уже существует, его содержимое будет удалено перед записью новых данных. Если файл не существует, он будет создан. Имя файла передается в функцию через параметр filename.
После создания потока выводится проверка, был ли файл успешно открыт с помощью метода is_open(). Если файл по какой-то причине не открылся (например, из-за отсутствия прав на запись или других ошибок), выводится сообщение об ошибке, и выполнение функции прекращается с помощью return.
Если файл открылся успешно, данные, содержащиеся в переменной code, записываются в файл с помощью оператора <<. Этот оператор записывает строку в поток вывода, который в данном случае связан с файлом. После завершения записи в файл, поток закрывается с помощью метода close(), что освобождает ресурсы, связанные с файлом, и завершает процесс записи.

3. Обработка кода и условных операторов
	Самой важной частью программы является обработка кода входного файла и его перезапись. Это выполняется с помощью следующего фрагмента кода:
![image](https://github.com/user-attachments/assets/af441b92-5bcb-4844-96a4-d7f0bb186f8e)

 
Этот код выполняет обработку строки code, извлекая условие (if) и выполняя различные операции над ними. С помощью find() мы ищем первое вхождение if в коде. Если он найден, метод возвращает индекс первого символа вхождения, и этот индекс сохраняется в переменной if_pos. Если он не найдено, метод возвращает специальное значение std::string::npos, которое сигнализирует о том, что вхождение отсутствует.
Затем начинается цикл while, который будет продолжаться, пока в строке есть вхождения if. Позиции скобок сохраняются в переменные open_paren и close_paren. Далее извлекается условие внутри скобок, используя метод substr(). Таким образом, переменная condition будет содержать условие конструкции if.
После этого начинается обработка блока кода, который следует за if. Для этого снова используется метод find(), чтобы найти позицию открывающей и закрывающей фигурной скобки { и }, соответственно. Эти позиции сохраняются в переменные open_brace и close_brace, а сам блок кода извлекается с помощью метода substr(). В результате переменная if_block будет содержать код, который находится внутри фигурных скобок после условия if.
Затем выполняются несколько операций над извлеченным блоком кода. С помощью функции std::replace заменяются символы новой строки на пробелы, чтобы избежать ненужных разрывов строк. После этого с помощью std::remove удаляются все символы точки с запятой (';') из строки.
![image](https://github.com/user-attachments/assets/cfbcf99d-f936-4382-bc58-d1beba28877a)

 
Этот код начинается с поиска else в строке code. Если else найден, то код продолжает искать открывающую и закрывающую фигурные скобки для блока кода, который следует за else. Для этого с помощью метода find() находятся позиции открывающей { } и закрывающей скобок, которые ограничивают блок кода после else. Если обе скобки найдены, то содержимое между ними извлекается с помощью метода substr(), и результат сохраняется в строковую переменную else_block.
После извлечения содержимого else выполняются операции замены символов. Все символы новой строки заменяются на пробелы с помощью std::replace(), чтобы избежать проблем с форматированием при дальнейшей обработки. Кроме того, символы точки с запятой (;) удаляются с помощью std::remove().
Далее создается тернарное выражение, объединяя условие if и else в одну строку, которая будет представлять собой тернарный оператор в виде:
условие ? (код при выполнении условия) ∶(код альтернативной ветви);
После этого продолжается поиск следующего вхождения конструкции if, начиная с позиции, где был вставлен тернарный оператор, чтобы обработать возможные следующие условные операторы.


4. Работа программы на практике
После запуска программы пользователя встречает диалоговое окно:
![image](https://github.com/user-attachments/assets/d5499446-2362-471e-a546-3dd35e31b32c)

 
Выводится надпись «МФТИ – Московский физико-технический институт», а также окно для ввода названия входного файла. Он должен находиться в той же корневой папке, что и сама программа. Например: «testik.cpp».
![image](https://github.com/user-attachments/assets/427dd5ae-72a3-4b40-9344-e40d7e717e59)

 
После ввода названия программа открывает входной файл, заменяет в нем условные операторы на тернарные, вносит изменения в файл, сохраняет его  и закрывает.

Заключение
В рамках данного проекта была разработана программа для автоматического преобразования условных операторов в тернарные операторы на языке программирования C++. Преобразование условных операторов в тернарные операторы позволяет значительно сократить объем кода, улучшить его читаемость и уменьшить количество потенциальных ошибок, связанных с неверным использованием условных конструкций. Программа успешно справляется с задачей замены как простых условных операторов, так и более сложных конструкций с альтернативными ветвями и несколькими условиями.
Основной задачей проекта было создание алгоритма, который бы корректно обрабатывал различные виды условных операторов в коде. В процессе работы над проектом были рассмотрены различные варианты использования условных операторов, что позволило выработать подходы для их правильной замены на тернарные операторы.
В заключение можно сказать, что проект успешно решает поставленную задачу, демонстрируя возможности языка C++ и стандартных библиотек для автоматизации рутинных задач.

Список использованных источников и литературы
Сетевые ресурсы
	C++ - файловые потоки: открытие и закрытие [Электронный ресурс]. - URL: https://metanit.com/cpp/tutorial/8.2.php?ysclid=m417slppmd888960387, Режим доступа: свободный. Дата обращения: 16.11.2024.
	Чтение и запись в файл с++ используя класс fstream c++. Изучение С++ для начинающих. Урок #118 [Электронный ресурс]. - URL: https://www.youtube.com/watch?v=bTysglLJ8No, Режим доступа: свободный. Дата обращения: 17.11.2024.
	Потоковые классы и Строки в С++ / Ravesli [Электронный ресурс]. - URL: https://ravesli.com/urok-210-potokovye-klassy-i-stroki/?ysclid=m417x9oil585663771, Режим доступа: свободный. Дата обращения: 17.11.2024.
