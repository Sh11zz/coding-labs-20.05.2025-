#include <iostream>
using namespace std;

class vect
{
public:
    int dim; // Размерность вектора
    double* b; // Массив элементов вектора
    int num; // Уникальный номер вектора
    static int count; // Счётчик векторов

    // Конструктор
    vect(int d) : dim(d), num(++count)
    {
        b = new double[dim];
        for (int i = 0; i < dim; ++i)
        {
            b[i] = 0; // Инициализация нулями
        }
    }

    // Деструктор
    ~vect()
    {
        delete[] b;
        cout << "Vector " << num << " destroyed" << endl;
    }

    // Оператор сложения
    vect operator+(const vect& v)
    {
        vect result(dim);
        for (int i = 0; i < dim; ++i)
        {
            result.b[i] = b[i] + v.b[i];
        }
        cout << "Adding vectors " << num << " and " << v.num << endl;
        return result;
    }

    // Оператор вычитания
    vect operator-(const vect& v)
    {
        vect result(dim);
        for (int i = 0; i < dim; ++i)
        {
            result.b[i] = b[i] - v.b[i];
        }
        cout << "Subtracting vectors " << num << " and " << v.num << endl;
        return result;
    }

    // Оператор отрицания
    vect operator-()
    {
        vect result(dim);
        for (int i = 0; i < dim; ++i)
        {
            result.b[i] = -b[i];
        }
        cout << "Negating vector " << num << endl;
        return result;
    }

    // Оператор скалярного произведения
    double operator*(const vect& v)
    {
        double result = 0;
        for (int i = 0; i < dim; ++i)
        {
            result += b[i] * v.b[i];
        }
        cout << "Dot product of vectors " << num << " and " << v.num << endl;
        return result;
    }

    // Оператор умножения на скаляр
    vect operator*(double k) 
    {
        vect result(dim);
        for (int i = 0; i < dim; ++i)
        {
            result.b[i] = k * b[i];
        }
        cout << "Multiplying vector " << num << " by scalar " << k << endl;
        return result;
    }

    // Оператор присваивания
    vect& operator=(const vect& v)
    {
        if (this != &v)
        {
            delete[] b;
            dim = v.dim;
            b = new double[dim];
            for (int i = 0; i < dim; ++i)
            {
                b[i] = v.b[i];
            }
            cout << "Copying vector from " << v.num << " to " << num << endl;
        }
        return *this;
    }
};

int vect::count = 0;

class matr
{
public:
    int dim; // Размерность матрицы
    double** a; // Двумерный массив элементов
    int num; // Уникальный номер матрицы
    static int count; // Счётчик матриц

    // Конструктор
    matr(int d) : dim(d), num(++count)
    {
        a = new double*[dim];
        for (int i = 0; i < dim; ++i)
        {
            a[i] = new double[dim];
            for (int j = 0; j < dim; ++j)
            {
                a[i][j] = 0; // Инициализация нулями
            }
        }
    }

    // Деструктор
    ~matr()
    {
        for (int i = 0; i < dim; ++i)
        {
            delete[] a[i];
        }
        delete[] a;
        cout << "Matrix " << num << " destroyed" << endl;
    }

    // Оператор сложения матриц
    matr operator+(const matr& m)
    {
        matr result(dim);
        for (int i = 0; i < dim; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                result.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        cout << "Adding matrices " << num << " and " << m.num << endl;
        return result;
    }

    // Оператор вычитания матриц
    matr operator-(const matr& m)
    {
        matr result(dim);
        for (int i = 0; i < dim; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                result.a[i][j] = a[i][j] - m.a[i][j];
            }
        }
        cout << "Subtracting matrices " << num << " and " << m.num << endl;
        return result;
    }

    // Оператор отрицания матрицы
    matr operator-()
    {
        matr result(dim);
        for (int i = 0; i < dim; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                result.a[i][j] = -a[i][j];
            }
        }
        cout << "Negating matrix " << num << endl;
        return result;
    }

    // Оператор умножения матриц
    matr operator*(const matr& m)
    {
        matr result(dim);
        for (int i = 0; i < dim; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                result.a[i][j] = 0;
                for (int k = 0; k < dim; ++k)
                {
                    result.a[i][j] += a[i][k] * m.a[k][j];
                }
            }
        }
        cout << "Multiplying matrices " << num << " and " << m.num << endl;
        return result;
    }

    // Оператор умножения на скаляр
    matr operator*(double k)
    {
        matr result(dim);
        for (int i = 0; i < dim; ++i)
        {
            for (int j = 0; j < dim; ++j)
            {
                result.a[i][j] = k * a[i][j];
            }
        }
        cout << "Multiplying matrix " << num << " by scalar " << k << endl;
        return result;
    }

    // Оператор присваивания
    matr& operator=(const matr& m)
    {
        if (this != &m) {
            for (int i = 0; i < dim; ++i)
            {
                delete[] a[i];
            }
            delete[] a;

            dim = m.dim;
            a = new double*[dim];
            for (int i = 0; i < dim; ++i)
            {
                a[i] = new double[dim];
                for (int j = 0; j < dim; ++j)
                {
                    a[i][j] = m.a[i][j];
                }
            }
            cout << "Copying matrix from " << m.num << " to " << num << endl;
        }
        return *this;
    }

    // Умножение матрицы на вектор
    vect operator*(const vect& v)
    {
        vect result(dim);
        for (int i = 0; i < dim; ++i)
        {
            result.b[i] = 0;
            for (int j = 0; j < dim; ++j)
            {
                result.b[i] += a[i][j] * v.b[j];
            }
        }
        cout << "Multiplying matrix " << num << " by vector " << v.num << endl;
        return result;
    }
};

int matr::count = 0;

int main()
{
    vect v1(3);
    vect v2(3);

    v1.b[0] = 1.0; v1.b[1] = 2.0; v1.b[2] = 3.0;
    v2.b[0] = 4.0; v2.b[1] = 5.0; v2.b[2] = 6.0;

    vect v3 = v1 + v2;
    vect v4 = v1 - v2;
    vect v5 = -v1;

    matr m1(3);
    matr m2(3);

    m1.a[0][0] = 1.0; m1.a[0][1] = 2.0; m1.a[0][2] = 3.0;
    m1.a[1][0] = 4.0; m1.a[1][1] = 5.0; m1.a[1][2] = 6.0;
    m1.a[2][0] = 7.0; m1.a[2][1] = 8.0; m1.a[2][2] = 9.0;

    m2.a[0][0] = 9.0; m2.a[0][1] = 8.0; m2.a[0][2] = 7.0;
    m2.a[1][0] = 6.0; m2.a[1][1] = 5.0; m2.a[1][2] = 4.0;
    m2.a[2][0] = 3.0; m2.a[2][1] = 2.0; m2.a[2][2] = 1.0;

    matr m3 = m1 + m2;
    matr m4 = m1 - m2;
    matr m5 = -m1;

    matr m6 = m1 * m2;

    matr m7 = m1 * 2.5;

    vect v6 = m1 * v1;

    return 0;
}