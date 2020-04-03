По заданию на языке C++ был реализован циклический буфер FIFO

## **List.cpp**

В файле *List.cpp* представлена реализация буфера с помощью циклического односвязного списка.
Реализованы методы:
*void enqueue(int value)* - метод реализующий добавление элемента со значением *value* в буфер

*int dequeue()*           - метод удаляющий наиболее старый элемент буфера и возвращающий его значение

*iunsigned int size()*    - метод возвращающий количество элементов в буфере

*bool isEmpty()*          - флаг пустоты буфера

*int first()*             - метод возвращающий значение первого в очереди элемента


Для оптипимальной работы указателей использовались smart pointers, а конкретно shared_ptr. 
Это позволяет оптимально работать с памятью и избежать ее утечек.


**Плюсы реализации:**

1. Операции добавление и удаления элементов имеют временную сложность Θ(1), что лучше чем у вектора
2. Буфер в данной реализации проще закольцевать.
3. Благодаря использованию smart pointers избегаются утечки памяти.

**Минусы реализации**

1. Требуется большее количество времени на написание кода.
2. Сложность в понимании кода.
3. Операция доступа к элементу имеет временную сложность Θ(n), что хуже чем у вектора.
4. Больше количество задействованной памяти.
5. Опасности связанные с использованием указателей.


## **Vector.cpp**

В файле *Vector.cpp* представлена реализация буфера с помощью вектора.
Реализованы методы:
*void enqueue(int value)* - метод реализующий добавление элемента со значением ** в буфер

*int dequeue()*           - метод удаляющий наиболее старый элемент буфера и возвращающий его значение

*int first()*             - метод возвращающий значение первого в очереди элемента

*int size_of()*           - метод возвращающий размер буффера

*bool isEmpty()*          - флаг пустоты буфера

Цикличность обеспечивается обработкой индексов вектора. Как только количество элементов выходит за рамки размера буфера,
индекс принудительно возвращается в 0.

Благодаря инициализации вектора вида:
```cpp

vector<int> buff;
buff.reserve(size);

```
выигрывается немного производительности при инициализации буфера.


**Плюсы реализации:**

1. Операция "доступа" к элементу имеет временную сложность Θ(1), что лучше чем у списка
2. Написать данную реализацию быстрее.
3. Читабельность кода выше чем у реализации через список.
4. Количество расходуемой памяти меньше.

**Минусы реализации**

1. Сложность в понимании кода.
2. Операция вставки и удаления элемента имеет временную сложность Θ(n), что хуже чем у списка.
3. Создание закольцованности вектора, что не позволяет использовать некоторые методы (например *.push_back(value)*)