//  функция создания двумерного динамического массива
int** Allocate(int rows, int cols);

//  функция создания двумерного динамического массива
void Allocate(int**& p, int rows, int cols);

// функция удаления двумерного динамического массива
void Free(int** p, int rows);

// функция инициализации массива
void Init(int** p, int rows, int cols);

// функция печати массива
void Print(int** p, int rows, int cols);

// функция добавления строки (одномерного массива) в конец двухмерного массива
int** AddStringEnd(int** p, int* rows, int cols, const int* mas);

// функция добавления строки (одномерного массива) в начало двухмерного массива
int** AddStringBegin(int** p, int* rows, int cols, const int* mas);

// функция добавления строки (одномерного массива) в начало двухмерного массива
void AddStringBegin(int**& p, int& rows, int cols, const int* mas);

// функция вставки строки (одномерного массива) в указанную позицию двухмерного массива
int** InsertString(int** p, int* rows, int cols, int index, const int* mas);

// Функция, удаляющая строку (одномерный массив) в двумерном динамическом массиве по указанному индексу.
int** DeleteString(int** p, int* rows, int cols, int index);

// Функция, удаляющая строку (одномерный массив) в двумерном динамическом массиве по указанному индексу.
void DeleteString(int**& p, int& rows, int cols, int index);

//  функция добавления столбца (одномерного массива) в конец двухмерного массива
int** AddColumnEnd(int** p, int rows, int* cols, const int* mas);

//  функция добавления столбца (одномерного массива) в начало двухмерного массива
int** AddColumnBegin(int** p, int rows, int* cols, const int* mas);

//  функция добавления столбца (одномерного массива) в начало двухмерного массива
void AddColumnBegin(int**& p, int rows, int& cols, const int* mas);

// функция вставки столбца (одномерного массива) в указанную позицию двухмерного массива
int** InsertColumn(int** p, int rows, int* cols, int index, const int* mas);

// функция удаления столбца (одномерного массива) по указанному индексу двухмерного массива
int** DeleteColumn(int** p, int rows, int* cols, int index);

// функция удаления столбца (одномерного массива) по указанному индексу двухмерного массива
void DeleteColumn(int**& p, int rows, int& cols, int index);

// Функция, копирует двумерный динамический массив в
// одномерный динамический массив.
int* Copies2DimDynArrTo1DimDynArr(int** p, int rows, int cols);

// Функция, копирует двумерный динамический массив в
// одномерный динамический массив.
void Copies2DimDynArrTo1DimDynArr(int**& p, int rows, int cols, int*& arr);