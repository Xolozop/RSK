# Алгоритм RSK

Классический алгоритм Робинсона-Шенстеда-Кнута (RSK) — это метод, используемый для построения пары таблиц Юнга (таблиц Юнга) из перестановки или последовательности чисел. Он имеет важное значение в комбинаторике и теории представлений.

<figure>
 <p align="center" width="100%">
  <img src="images/result.png">
  <figcaption><p align=center>Результат работы алгоритма для перестановки σ = (7 5 1 2 6 4 3)</p></figcaption>
 </p>
</figure>

[Визуализация работы алгоритмов](https://xolozop.github.io//rsk-visualization/)

## Применение алгоритма RSK

Алгоритм RSK используется для изучения структуры перестановок и их свойств. Он позволяет связать перестановки с таблицами Юнга, что является важным инструментом в комбинаторной теории. Также алгоритм играет ключевую роль в алгебраической комбинаторике, где он используется для изучения симметрических функций, таких как функции Шура. Алгоритм RSK также используется для изучения цепей и антицепей в перестановках. Цепь в перестановке — это последовательность элементов, каждый из которых меньше следующего. Антицепь — это последовательность элементов, каждый из которых больше следующего. Алгоритм RSK помогает определить длину наибольшей цепи и антицепи в перестановке, что важно для изучения свойств перестановок и их структуры.

## Основные шаги алгоритма классического RSK
### Инициализация:

Создаются две пустые таблицы: таблица P (таблица вставки) и таблица Q (таблица записи).
Первый элемент перестановки добавляется в первую строку таблицы P, а в таблицу Q добавляется индекс этого элемента — для первого элемента это 1.
### Основной цикл:

Для каждого элемента перестановки, начиная со второго, выполняется процесс вставки в таблицу P и обновления таблицы Q.
### Вставка элемента в таблицу P:

Элемент *a* вставляется в первую строку таблицы P, согласно следующим правилам:
1. Если *a* больше последнего элемента в строке, он добавляется в конец строки.
2. Если *a* меньше или равен последнему элементу, ищется первый элемент в строке, который больше *a*. Этот элемент выталкивается и заменяется на *a*. Процесс повторяется для следующей строки с выталкиваемым элементом, пока не будет найдена строка (в том числе пустая), в которую можно добавить элемент в конец.
### Обновление таблицы Q:

В таблицу Q добавляется индекс текущего элемента перестановки в ту же строку, в которую был добавлен элемент в таблицу P.

<figure>
 <p align="center" width="100%">
  <img src="images/classical/steps.png">
  <figcaption><p align=center>Шаги классического алгоритма для перестановки σ = (7 5 1 2 6 4 3)</p></figcaption>
 </p>
</figure>

# Геометрическая конструкция Вьенно
Геометрическая конструкция Вьенно (Viennot) — это визуальный метод для представления и понимания алгоритма RSK. Этот метод использует аналогию со светом и тенями для визуализации процесса вставки элементов перестановки в таблицы Юнга.

## Основная суть геометрической конструкции Вьенно
Представьте себе, что в левом нижнем углу таблицы находится источник света. Свет распространяется по таблице снизу вверх и слева направо. Каждая точка (элемент перестановки) отбрасывает тень на таблицу. Тень распространяется вверх и вправо от точки.
Если свет попадает на точку, он отбрасывает тень, которая блокирует свет для других точек, находящихся выше и правее.

## Процесс построения:

### Инициализация:
Строится поле размера n на n (где n — размер перестановки). После чего каждый элемент перестановки представляется на этом поле как точка с координатами (*i*, σ(*i*)):

<figure>
 <p align="center" width="100%">
  <img src="images/geometrical/start.png">
  <figcaption><p align=center>Первоначальная инициализация поля для перестановки σ = (7 5 1 2 6 4 3)</p></figcaption>
 </p>
</figure>

Элементы перестановки вставляются в таблицу по определенным правилам. Если элемент больше последнего элемента в строке, он добавляется в конец строки.
Если элемент меньше или равен последнему элементу, он выталкивает первый элемент, который больше его, и процесс повторяется для следующей строки.

### Основной цикл:
Строим тени по заданным точкам, при пересечение двух теней одинакового порядка, "путь" тени преломляется и образует ломаную линию. Точка пересечения двух теней становится точкой новой перестановки, называемой скелетом.

<figure>
 <p align="center" width="100%">
  <img src="images/geometrical/skeleton.png">
  <figcaption><p align=center>Первые шаги и скелет для перестановки σ = (7 5 1 2 6 4 3)</p></figcaption>
 </p>
</figure>

*Цветом обозначен порядок скелета*

Алгоритм повторяется для точек новообразованного скелета, пока существуют точки пересечения между тенями. 

<figure>
 <p align="center" width="100%">
  <img src="images/geometrical/result.png">
  <figcaption><p align=center>Результат работы геометрической конструкции Вьенно для перестановки σ = (7 5 1 2 6 4 3)</p></figcaption>
 </p>
</figure>

### Результат работы алгоритма
В результате получим поле, разбитое тенями, образованными различными скелетами, пронумерованными в порядке возникновения. На иллюстрации видно, что порядки верхних и правых продолжений теней образуют определённый код, называемым кодом Яманучи. 
Код Яманучи — это код, показывающий, в какой строке таблицы Юнга стоит *i*-ый элемент перестановки.

# Алгоритм RSK с локальными правилами для рёбер

Алгоритм Робинсона-Шенстеда-Кнута (RSK) с локальными правилами для рёбер (edge local rules) используется для построения таблиц Юнга из диаграммы Феррерса (Ferrers diagram). В этом алгоритме каждая клетка сетки может содержать точку или быть пустой, а рёбра каждой клетки помечены неотрицательными целыми числами. Локальные правила определяют, как метки рёбер изменяются в зависимости от содержимого клетки и её соседей.

## Шаги алгоритма

Начнем с диаграммы Феррерса, где каждая клетка может содержать точку или быть пустой. Рёбра каждой клетки помечены неотрицательными целыми числами. Для каждой клетки c применяются локальные правила для определения меток рёбер W(c), E(c), S(c), и N(c) (западное, восточное, южное и северное рёбра соответственно).

<figure>
 <p align="center" width="100%">
  <img src="images/edge local rules/start.png">
  <figcaption><p align=center>Первоначальная инициализация поля для перестановки σ = (7 5 1 2 6 4 3)</p></figcaption>
 </p>
</figure>

## Локальные правила

### Правило (I):
Если метки западного и южного рёбер разные (W(c) = i и S(c) = j, где i ≠ j), то метка восточного ребра становится равной метке западного ребра (E(c) = i), а метка северного ребра становится равной метке южного ребра (N(c) = j).

### Правило (II):
Если метки западного и южного рёбер одинаковы и больше нуля (W(c) = S(c) = i > 0), то метки восточного и северного рёбер увеличиваются на 1 (E(c) = N(c) = i + 1).

### Правило (III):
Если метки западного и южного рёбер равны нулю (W(c) = S(c) = 0):
- Если клетка пустая, то метки восточного и северного рёбер остаются равны нулю (E(c) = N(c) = 0).
- Если клетка содержит чёрную точку, то метки восточного и северного рёбер становятся равны 1 (E(c) = N(c) = 1).

<figure>
 <p align="center" width="100%">
  <img src="images/edge local rules/rules.png">
  <figcaption><p align=center>Локальные правила на рёбрах</p></figcaption>
 </p>
</figure>

### Результат работы алгоритма
В результате получим диаграмму Феррерса, северные и восточные рёбра которой образуют код Яманучи таблиц P и Q соответственно.

<figure>
 <p align="center" width="100%">
  <img src="images/edge local rules/result.png">
  <figcaption><p align=center>Результат работы алгоритма для перестановки σ = (7 5 1 2 6 4 3)</p></figcaption>
 </p>
</figure>

*Цвета соответствуют числовым значениям на ребрах*

## Программная реализация
Перестановки и таблицы Юнга представлены как векторы.
### Классический RSK
Циклически происходит вставка i-того элемента перестановки, в случае, если элемент невозможно вставить в конец, линейным поиском (начиная с конца строки) находится первый не превосходящий и "выталкивается", процесс вставки данного элемента повторяется в строке выше (однако при надобности линейный поиск теперь будет осуществляться не с конца, а с позиции, откуда элемент был вытолкнут).
### Геометрическая конструкция Вьенно
Для хранения координат точек (*i*, σ(*i*)) используется контейнер map языка C++, в качестве ключа используется *i*, значение соответствует σ(*i*). Данная структура позволяет хранить расположение точек в порядке возрастания по оси *X*, а также быстро удалять уже использованные в построение точки. Во внешнем цикле осуществляется построение очередного набора теней для текущей перестановки: для этого для каждой последующей точки перестановки находится точка, расположенная правее и ниже текущей (при наличии таковой), процесс поиска повторяется до тех пор, пока не достигнут конец поля или пока тень не достигла своей максимальной глубины (тени не могут пересекаться, поэтому осуществлять поиск выше границы тени, полученной на предыдущем шаге смысла не имеет). Скелет также представляет собой контейнер map, что позволяет применить к нему аналогичный процесс.
### С локальными правилами на рёбрах
Алгоритм RSK с локальными правилами на ребрах использует структуру Cell для хранения информации о ребрах ячеек и наличии точек. Функция принимает перестановку и возвращает таблицы P и Q. Основные шаги: инициализация таблиц P и Q, определение размера перестановки n, создание векторов current и next для текущей и следующей строки ячеек. Внешний цикл проходит по строкам, внутренний — по столбцам. Если ячейка содержит точку, устанавливаются значения правого и верхнего ребер. Если нижнее и левое ребра ячейки равны и не равны нулю, обновляются правое и верхнее ребра. Иначе, правое ребро принимает значение левого, а верхнее — нижнего. Левое ребро следующей ячейки и нижнее ребро следующей строки обновляются значениями правого и верхнего ребер текущей ячейки. Если текущая строка последняя, обновляется таблица Q. После внутреннего цикла обновляется таблица P. Векторы current и next меняются местами для перехода к следующей строке. Функция возвращает таблицы P и Q.


## Оценка сложности алгоритмов по времени

|       | Классический RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
| :---: | :--------------: | :-------------------------------: | :-------------------------: |
| Лучший случай  | O(n) | O(n) | O(n<sup>2</sup>) |
| Средний случай | O(n∙log*n*) | O(n<sup>2</sup>) | O(n<sup>2</sup>) |
| Худший случай  | O(n<sup>2</sup>) | O(n!) | O(n<sup>2</sup>) |

 
## Практическая часть
### Постановка задачи
Целью данной работы является изучение описанных выше реализаций RSK-алгоритма на эффективность для разных видов перестановок:
1. Упорядоченные перестановки
2. Равновероятностно случайно сгенерированные перестановки (реализовано при помощи тасования Фишера-Йетса)
3. Перестановки с чередованием элементов по превосходству значения
4. Перестановки с *k* убывающими наборами упорядоченных по возрастанию элементов

### Результаты тестов
#### 1. Упорядоченные перестановки

* **Отсортированные по возрастанию:**
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>
 
| Размер перестановки | Классический RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |     0,000601     |              1,012853             |           1,865204          |
|        20000        |     0,001176     |              4,553336             |           7,349247          |
|        30000        |     0,001403     |             10,359313             |          16,629676          |
|        40000        |     0,002326     |              20,50435             |          29,676795          |
|        50000        |     0,003181     |             30,009863             |          46,821235          |
|        60000        |     0,003562     |             46,052499             |          68,628814          |
|        70000        |     0,004453     |             52,434982             |          92,063661          |
|        80000        |     0,004686     |             71,213713             |          121,730855         |
|        90000        |     0,006243     |             90,327396             |          156,004862         |
|        100000       |     0,005994     |             115,367426            |          189,363872         |
|       1000000       |     0,065322     |                -                  |                -            |
|       5000000       |      0,28655     |                -                  |                -            |
|       10000000      |      0,64035     |                -                  |                -            |
|       20000000      |     1,134262     |                -                  |                -            |
|       30000000      |     1,643549     |                -                  |                -            |
|       40000000      |     2,248155     |                -                  |                -            |
|       50000000      |     2,812592     |                -                  |                -            |
|       60000000      |     3,317126     |                -                  |                -            |
|       70000000      |     3,960854     |                -                  |                -            |
|       80000000      |     4,486956     |                -                  |                -            |
|       90000000      |     5,029126     |                -                  |                -            |
|      100000000      |     5,613978     |                -                  |                -            |

</details>

| График для N ≤ 100,000         | График для N ≤ 100,000,000 (только классический RSK) |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/1-1-a.png">|<img src="images/graphs/1-1-b.png">|

* **Отсортированные по убыванию:**
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

| Размер перестановки | Классический RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |     0,847699     |              21,49496             |           2,070853          |
|        20000        |     3,380799     |             90,150484             |           8,323989          |
|        30000        |     7,626516     |             207,872435            |          18,486401          |
|        40000        |     13,440646    |             375,86348             |          33,482745          |
|        50000        |     21,881444    |               -                   |          52,239786          |
|        60000        |     31,790478    |               -                   |           75,44334          |
|        70000        |     42,609374    |               -                   |          103,082618         |
|        80000        |     55,388925    |               -                   |          134,076748         |
|        90000        |     71,027995    |               -                   |          169,092204         |
|        100000       |     87,986997    |               -                   |          209,612958         |
|        200000       |    354,548989    |               -                   |               -             |
|        300000       |    796,467758    |               -                   |               -             |
 
</details>

| График для N ≤ 100,000         | График для N ≤ 300,000 |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/1-2-a.png">|<img src="images/graphs/1-2-b.png">|

#### 2. Равновероятностно случайно сгенерированный перестановки

<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

| Размер перестановки | Классический RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|         5000        |     0,006786     |              0,191663             |           0,517125          |
|        10000        |     0,018688     |              0,705417             |           2,157886          |
|        20000        |     0,052414     |              2,751804             |           8,767269          |
|        30000        |     0,095056     |              5,88774              |          19,907607          |
|        40000        |     0,147975     |             11,515333             |          35,057829          |
|        50000        |     0,205241     |             18,785126             |           55,54157          |
|        60000        |     0,273232     |             26,653572             |          80,467768          |
|        70000        |     0,342607     |             37,687104             |          108,480195         |
|        80000        |      0,41598     |             59,562964             |          142,267939         |
|        90000        |     0,500772     |             76,224148             |          181,586406         |
|        100000       |      0,5835      |             99,642887             |          219,837433         |
|  200000 |  1,636891  | - | - |
|  300000 |  3,307881  | - | - |
|  400000 |  4,823599  | - | - |
|  500000 |   7,35265  | - | - |
|  600000 |  10,080268 | - | - |
|  700000 |  14,884318 | - | - |
|  800000 |  20,242834 | - | - |
|  900000 |  31,206611 | - | - |
| 1000000 |  34,660817 | - | - |
| 2000000 | 133,265003 | - | - |
| 3000000 | 283,223861 | - | - |
| 4000000 | 463,901863 | - | - |
| 5000000 | 670,189398 | - | - |

</details>

| График для N ≤ 100,000         | График для N ≤ 5,000,000 |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/2-a.png">|<img src="images/graphs/2-b.png">|

#### 3. Перестановки с чередованием элементов по превосходству значения

* **Возрастающие чередующиеся перестановки:**
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

 | Размер перестановки | Классичечкий RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |     0,000674     |              0,864057             |           1,906902          |
|        20000        |      0,00112     |              3,379879             |           7,312008          |
|        30000        |     0,001648     |              8,387098             |          16,983678          |
|        40000        |     0,002254     |             14,294379             |          30,134296          |
|        50000        |     0,002733     |             24,171579             |          47,421533          |
|        60000        |     0,003416     |             37,832094             |          69,049504          |
|        70000        |      0,00381     |             54,820734             |           94,15878          |
|        80000        |     0,004327     |             67,870673             |          121,184905         |
|        90000        |     0,004888     |             83,966969             |          158,076804         |
|        100000       |     0,005704     |             143,074447            |          191,798039         |
|   500000  | 0,032741 | - |  - |
|  1000000  | 0,061743 | - |  - |
|  5000000  |   0,285  | - |  - |
|  10000000 | 0,564176 | - |  - |
|  20000000 | 1,171571 | - |  - |
|  30000000 | 1,732969 | - |  - |
|  40000000 | 2,293166 | - |  - |
|  50000000 | 2,905438 | - | -- |
|  60000000 | 3,463534 | - |  - |
|  70000000 | 4,097522 | - | -- |
|  80000000 | 4,643377 | - |  - |
|  90000000 | 5,233776 | - |  - |
| 100000000 | 5,845777 | - |  - |

</details>

| График для N ≤ 100,000        | График для N ≤ 100,000,000 (только классический RSK) |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/3-1-a.png">|<img src="images/graphs/3-1-b.png">|

* **Убывающие чередующиеся перестановки:****
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

| Размер перестановки | Классичечкий RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |     0,579611     |             13,034815             |           2,108384          |
|        20000        |      2,26554     |              54,19598             |           8,198634          |
|        30000        |     5,173103     |             125,488354            |          18,559585          |
|        40000        |     9,172545     |             227,065119            |           33,40944          |
|        50000        |     14,792663    |             355,379732            |          52,042821          |
|        60000        |     20,442118    |                 -                 |          71,049291          |
|        70000        |     28,380505    |                 -                 |          99,283188          |
|        80000        |     36,355957    |                 -                 |          129,697987         |
|        90000        |     45,700037    |                 -                 |          164,442745         |
|        100000       |     56,831886    |                 -                 |          207,986803         |
|        200000       |    236,228265    |                 -                 |              -              |
 
</details>
<figure>
 <p align="center" width="70%">
  <img src="images/graphs/3-2.png">
  <figcaption><p align=center>Результат работы алгоритма для N ≤ 200,000</p></figcaption>
 </p>
</figure>

#### 4. Перестановки с *k* убывающими наборами упорядоченных по возрастанию элементов

Перестановки вида `j*k j*k+1 ... j*k (j-1)*k (j-1)*k+1 ... k 1 ... k-1`

* **Для k = 5:**
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

| Размер перестановки | Классичечкий RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |     0,234185     |              4,45674              |           2,154915          |
|        20000        |     0,932223     |             18,205519             |           8,612712          |
|        30000        |     2,097599     |             41,828989             |          19,430824          |
|        40000        |     3,741172     |              75,8145              |          34,690088          |
|        50000        |     5,909467     |             120,927855            |          54,326158          |
|        60000        |     8,521054     |             175,127442            |          76,987542          |
|        70000        |     11,419294    |             238,296511            |          105,092895         |
|        80000        |     14,931195    |             310,32173             |          137,908733         |
|        90000        |     19,856811    |             400,429312            |          175,584222         |
|        100000       |     24,716599    |             500,210205            |          217,45459          |
|        200000       |     32,75725     |                 -                 |              -              |
|        300000       |    125,888609    |                 -                 |              -              |
|        400000       |    284,527445    |                 -                 |              -              |
|        500000       |    530,399831    |                 -                 |              -              |
|        600000       |    843,600267    |                 -                 |              -              |
|        700000       |    1237,210432   |                 -                 |              -              |

</details>

| График для N ≤ 100,000         | График для N ≤ 700,000 |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/4-1-a.png">|<img src="images/graphs/4-1-b.png">|


* **Для k = 10:**
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

| Размер перестановки | Классичечкий RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |      0,12196     |              2,614125             |           2,061663          |
|        20000        |     0,483032     |             10,907411             |           8,284214          |
|        30000        |     1,108067     |             24,937644             |          19,215925          |
|        40000        |     1,970311     |             44,605472             |          34,682482          |
|        50000        |     3,349261     |             71,132547             |          53,447393          |
|        60000        |     4,391315     |             104,682211            |          76,449746          |
|        70000        |     6,018155     |             144,556844            |          105,172482         |
|        80000        |     8,157654     |             193,089229            |          137,034881         |
|        90000        |     9,931372     |             244,215886            |          171,393149         |
|        100000       |     13,802051    |             305,494216            |          213,945409         |
|        200000       |     57,398585    |                 -                 |              -              |
|        300000       |    141,952426    |                 -                 |              -              |
|        400000       |    242,088606    |                 -                 |              -              |
|        500000       |    402,794213    |                 -                 |              -              |
|        600000       |    610,625716    |                 -                 |              -              |
|        700000       |    823,541659    |                 -                 |              -              |
|        800000       |    1086,400181   |                 -                 |              -              |

</details>

| График для N ≤ 100,000         | График для N ≤ 800,000 |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/4-2-a.png">|<img src="images/graphs/4-2-b.png">|

* **Для k = 20:**
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

| Размер перестановки | Классичечкий RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |     0,063536     |              1,648593             |           2,127123          |
|        20000        |     0,251512     |              6,656306             |           8,223205          |
|        30000        |     0,568187     |             15,269518             |          18,342155          |
|        40000        |     1,011124     |             27,610254             |           32,15714          |
|        50000        |     1,572525     |             45,527105             |          51,258602          |
|        60000        |     2,257808     |             65,613613             |          71,094849          |
|        70000        |      3,08855     |             90,150347             |          101,86655          |
|        80000        |     4,069858     |             125,375079            |          134,611256         |
|        90000        |     5,021152     |             162,157373            |          171,973327         |
|        100000       |     7,084877     |             196,032082            |          210,579045         |
|        200000       |     30,046802    |                 -                 |              -              |
|        300000       |     67,511012    |                 -                 |              -              |
|        400000       |    126,721405    |                 -                 |              -              |
|        500000       |    207,857765    |                 -                 |              -              |
|        600000       |    304,474467    |                 -                 |              -              |
|        700000       |    425,703013    |                 -                 |              -              |
|        800000       |    533,081112    |                 -                 |              -              |
|        900000       |    679,241603    |                 -                 |              -              |
|       1000000       |     858,88271    |                 -                 |              -              |

</details>

| График для N ≤ 100,000         | График для N ≤ 1,000,000 |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/4-3-a.png">|<img src="images/graphs/4-3-b.png">|

* **Для k = 50:**
<details>
  <summary><ins>Развернуть/скрыть таблицу результатов</ins></summary>

| Размер перестановки | Классичечкий RSK | Геометрическая конструкция Вьенно | Локальные правила на рёбрах |
|:-------------------:|:----------------:|:---------------------------------:|:---------------------------:|
|        10000        |     0,027637     |              1,008977             |           1,969885          |
|        20000        |     0,103605     |              4,068374             |           8,21048           |
|        30000        |     0,228511     |              9,493959             |          18,465258          |
|        40000        |     0,409519     |             17,603163             |          32,938348          |
|        50000        |     0,624881     |             26,259705             |          50,142233          |
|        60000        |     0,899817     |             40,194401             |          74,997935          |
|        70000        |     1,227709     |             56,423393             |          102,29151          |
|        80000        |      1,5956      |             76,636078             |          135,034539         |
|        90000        |     2,034806     |             105,616648            |          169,967795         |
|        100000       |     2,868901     |             133,944753            |          206,639468         |
|        200000       |     11,52634     |                 -                 |              -              |
|        300000       |     26,988498    |                 -                 |              -              |
|        400000       |     49,704898    |                 -                 |              -              |
|        500000       |     78,558758    |                 -                 |              -              |
|        600000       |    112,452287    |                 -                 |              -              |
|        700000       |    154,921634    |                 -                 |              -              |
|        800000       |    205,149767    |                 -                 |              -              |
|        900000       |     264,20813    |                 -                 |              -              |
|       1000000       |    327,434968    |                 -                 |              -              |

</details>

| График для N ≤ 100,000         | График для N ≤ 1,000,000 |
|:-----------------------------:|:------------------------:|
|<img src="images/graphs/4-4-a.png">|<img src="images/graphs/4-4-b.png">|

### Тестирование проводилось на ноутбуке со следующими параметрами: 
1. Модель процессора: AMD Ryzen 7 5700U
2. Общее количество ядер: 8
3. Максимальное число потоков: 16
4. Объём ОЗУ: 16 Гб
5. Видеокарта встроенная, 80 вычислительных блоков
   
Для написания кода был использован графический редактор Visual Studio Code, в качестве компилятора g++ версии 14.2.1, сборка проекта осуществлялась утилитой GNU Make версии 4.4.1.

## Заключение
Алгоритм RSK является фундаментальным инструментом в комбинаторике и теории представлений, предоставляя глубокие понимания в структуру перестановок и их связь с таблицами Юнга. Его применение выходит за рамки простого построения таблиц и включает в себя изучение симметрий, инвариантов и других важных комбинаторных объектов.
Классический RSK алгоритм показал себя как наиболее эффективный на всех тестах. Геометрическая конструкция Вьенно в среднем случае оптимальнее локальных правил на рёбрах (в частности для упорядоченных и частично упорядоченных по возрастанию перестановок).
Самую быструю скорость работы классический RSK показал на чередующихся последовательностях, геометрическая конструкция Вьенно - для случайных и упорядоченных перестановок. 

## Перспективы
В дальнейшем представляется возможным параллелизировать геометрическую конструкцию Вьенно для оптимизации процесса построения таблиц P и Q.
