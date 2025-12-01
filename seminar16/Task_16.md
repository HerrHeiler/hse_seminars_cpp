# **Problem 20: Симуляция частицы с вложенной структурой параметров среды**

Создайте физическую симуляцию частицы, движущейся в среде, параметры которой описывает вложенная структура.

### Контекст

Маленькая частица летит в вязкой среде. У неё есть масса, скорость и положение.
А у среды — плотность и коэффициент сопротивления.

### Требования

1. Класс `Particle` хранит:

   * `double x, y, vx, vy, mass;`
2. Внутри `Particle` создайте структуру `Environment`:

   ```cpp
   struct Environment {
       double density;
       double friction;
   };
   ```
3. Добавьте поле `Environment env;`
4. Реализуйте методы с использованием `this`:

   * `Particle& applyForce(double fx, double fy);` — изменение скорости.
   * `Particle& tick(double dt);` — шаг симуляции: обновляет `x`, `y` с учётом сопротивления среды.
5. Реализуйте делегирующие конструкторы:

   * полный: `(x, y, mass, env)`
   * упрощённый: `(mass)` — позиция = (0,0), скорость = (0,0), env = {1.0, 0.1}
6. Метод:

   ```cpp
   void print() const;
   ```

### Пример сценария

```cpp
Particle::Environment e{1.2, 0.05};
Particle p(0, 0, 1.0, e);

p.applyForce(10, 0).tick(0.1).tick(0.1);

p.print();
```

---

# **Problem 21: Редактор изображений с вложенными фильтрами и цепочкой операций**

Создайте систему обработки изображения, в которой фильтры оформлены как вложенные классы, а операции составляются цепочкой методов.

### Требования

1. Класс `Image` хранит двумерный массив (можно просто `std::vector<int>` + ширина/высота).
2. Внутри `Image` объявить вложенный класс `Filter`:

   ```cpp
   class Filter {
       int intensity;
   public:
       Filter(int i);
       int apply(int pixel) const; // использует this->intensity
   };
   ```
3. Реализовать методы:

   * `Image& applyBrightness(int delta);`
   * `Image& applyFilter(const Filter& f);`
4. Делегирующий конструктор:

   * `(w, h, init)` → заполняет все пиксели init
   * `(w, h)` → делегирует, используя init = 0
5. Метод:

   ```cpp
   void show() const;
   ```
6. В `main()`:

   * создать изображение,
   * применить цепочку фильтров:

     ```cpp
     img.applyBrightness(10)
        .applyFilter(Image::Filter(3))
        .applyBrightness(-5);
     ```
   * вывести результат.

---

# **Problem 22: Игровой объект с вложенной структурой состояния и безопасным копированием**

Создайте игрового персонажа, у которого есть вложенная структура боевых характеристик.

### Требования

1. Класс `Character` содержит:

   * `std::string name;`
   * вложенную структуру:

     ```cpp
     struct Stats {
         int hp;
         int attack;
         int defense;
     };
     ```
   * поле `Stats stats;`
2. Реализовать:

   * полный конструктор `(name, hp, attack, defense)`
   * копирующий конструктор
   * оператор присваивания с проверкой `this == &other`
3. Методы с использованием `this`:

   * `void hit(Character& target);`
   * `void heal(int amount);`
4. Метод `print()`.

### Пример сценария

```cpp
Character a("Hero", 100, 15, 5);
Character b("Goblin", 40, 8, 2);

a.hit(b);
b.print();
```

---

# **Problem 23: Файловая система с вложенными узлами Directory/File**

Создайте простую модель файловой системы, где каталог и файл представлены вложенными структурами.

### Требования

1. Класс `FS` содержит вложенные:

   ```cpp
   struct File   { std::string name; int size; };
   struct Folder { std::string name; std::vector<File> files; };
   ```
2. `FS` хранит:

   ```cpp
   Folder root;
   ```
3. Реализуйте методы:

   * `void addFile(const std::string& name, int size);`
   * `int totalSize() const;`
   * `void print() const;`
4. Используйте `this->root.files` в реализации.
5. Реализуйте копирующий оператор присваивания со стандартной проверкой `if (this == &other)`.

### Пример использования

```cpp
FS fs("home");
fs.addFile("notes.txt", 120);
fs.addFile("image.png", 10240);
fs.print();
```

---

# **Problem 24: Анимация объекта с вложенной временной шкалой и делегирующими конструкторами**

Создайте объект, который умеет проигрывать анимацию по времени.

### Требования

1. Класс `Animation` содержит:

   * `double currentTime;`
   * вложенную структуру:

     ```cpp
     struct Timeline {
         double start;
         double end;
         double speed;
     };
     ```
   * поле `Timeline timeline;`
2. Делегирующие конструкторы:

   * полный `(start, end, speed)`
   * упрощённый `(duration)` — `start = 0`, `end = duration`, `speed = 1`
3. Методы:

   * `Animation& update(double dt);` — увеличивает время с учётом `speed`.
   * `bool finished() const;`
   * `void print() const;`
4. Используйте `this->timeline.start` и `this->timeline.speed`.

### Пример

```cpp
Animation a(0, 3, 1.5);
a.update(1.0).update(1.0);
a.print();
```
