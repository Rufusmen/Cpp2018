//
// Created by rufus on 17.04.18.
//

#include <utility>
#include <cmath>
#include "Matrix.h"
#include "Invalid_size_exception.h"

namespace calc{
Matrix::Matrix(const int size, double var) : m(size), n(size) {
    tab = new double *[size];
    for (int i = 0; i < size; i++) {
        tab[i] = new double[size];
        for (int j = 0; j < size; j++)tab[i][j] = 0;
        tab[i][i] = var;
    }

}

Matrix::Matrix(const int n, const int m)throw(Invalid_size_exception) : m(m), n(n) {
    if(n<=0 || m<=0)throw Invalid_size_exception();
    tab = new double *[n];
    for (int i = 0; i < n; i++) {
        tab[i] = new double[m];
        for (int j = 0; j < m; j++)tab[i][j]=0;
    }
}

Matrix::Matrix(const Matrix &matrix) : m(matrix.m), n(matrix.n) {
    tab = new double *[n];
    for (int i = 0; i < n; ++i) {
        tab[i] = new double[m];
        for (int j = 0; j < m; ++j) {
            tab[i][j] = matrix.tab[i][j];
        }
    }
}

    Matrix::Matrix(Matrix &&matrix) noexcept : m(matrix.m), n(matrix.n) {
        tab = matrix.tab;
        matrix.tab = nullptr;
    }

    Matrix &Matrix::operator=(const Matrix &matrix) {
        if(&matrix == this)
            return *this;
        Matrix tmp(matrix);
        *this = std::move(tmp);
        return *this;
    }

    Matrix &Matrix::operator=(Matrix &&matrix) noexcept {
        this->~Matrix();
        m = matrix.m;
        n =matrix.n;
        tab = matrix.tab;
        matrix.tab = nullptr;
        matrix.m = 0;
        matrix.n = 0;
        return *this;
    }

    Matrix::~Matrix() {
        if(tab != nullptr){
            for (int i = 0; i < n; ++i) {
                delete tab[i];
            }
            delete[] tab;
        }
        tab = nullptr;
        n=0;m=0;
    }

    std::istream &operator>>(std::istream &we, Matrix &matrix) {
        for (int i = 0; i < matrix.n; ++i) {
            for (int j = 0; j < matrix.m; ++j) {
                we >> matrix.tab[i][j];
            }
        }
        return we;
    }

    std::ostream &operator<<(std::ostream &wy, const Matrix &matrix) {
        for (int i = 0; i < matrix.n; ++i) {
            for (int j = 0; j < matrix.m; ++j) {
                wy << matrix.tab[i][j] << " ";
            }
            wy << "\n";
        }
        return wy;
    }

    Matrix Matrix::operator*(double scalar) const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tab[i][j] *= scalar;
            }
        }
        return *this;
    }

    Matrix operator*(double scalar, const Matrix &matrix) {
        return Matrix(matrix)*scalar;
    }
    Matrix &Matrix::operator+=(const Matrix &matrix)throw(Invalid_size_exception) {
        if(m != matrix.m || n != matrix.n)throw Invalid_size_exception();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tab[i][j] += matrix.tab[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix &m1, const Matrix &m2)throw(Invalid_size_exception){
        return Matrix(m1)+=m2;
    }
    Matrix &Matrix::operator-=(const Matrix &matrix)throw(Invalid_size_exception) {
        if(m != matrix.m || n != matrix.n)throw Invalid_size_exception();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tab[i][j] -= matrix.tab[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix &m1, const Matrix &m2)throw(Invalid_size_exception) {
        return Matrix(m1)-=m2;
    }
    Matrix &Matrix::operator*=(const Matrix &matrix) throw(Invalid_size_exception){
        if(n != matrix.m || m != matrix.n)throw Invalid_size_exception();
        Matrix tmp(0,0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < matrix.m; ++k) {
                    tmp.tab[i][k] += tab[i][j] * matrix.tab[j][k];
                }
            }
        }
        *this = std::move(tmp);
        return *this;
    }

    Matrix operator*(const Matrix &m1, const Matrix &m2) throw(Invalid_size_exception){
        return Matrix(m1)*=m2;
    }

    Matrix Matrix::operator~() {
        Matrix tmp(m,n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tmp.tab[j][i]=tab[i][j];
            }
        }
        return tmp;
    }

    Matrix &Matrix::rowSwap(int i, int j) throw (Wrong_index_exception){
        if(i < 0 || j < 0 || i >= n || j >= n)throw Wrong_index_exception();
        if(i==j)return *this;
        std::swap(tab[i],tab[j]);
        return *this;
    }

    Matrix &Matrix::rowMult(int i, double scalar)throw (Wrong_index_exception) {
        if(i<0 || i>=n)throw Wrong_index_exception();
        for (int j = 0; j < m; ++j) {
            tab[i][j] *= scalar;
        }
        return *this;
    }

    Matrix &Matrix::rowAdd(int to, int from, double scalar) throw (Wrong_index_exception){
        if (to < 0 || to >= n || from < 0 || from >= n) throw Wrong_index_exception();
        if (scalar == 0) return *this;
        for (int i = 0; i < m; ++i) {
            tab[to][i] += tab[from][i] * scalar;
        }
        return *this;
    }

    Matrix &Matrix::colSwap(int i, int j) throw (Wrong_index_exception){
        if(i < 0 || j < 0 || i >= m || j >= m)throw Wrong_index_exception();
        if(i==j)return *this;
        for (int k = 0; k < n; ++k) {
            std::swap(tab[k][i],tab[k][j]);
        }
        return *this;
    }

    Matrix &Matrix::colMult(int i, double scalar) throw (Wrong_index_exception){
        if(i<0 || i>=m)throw Wrong_index_exception();
        for (int j = 0; j < n; ++j) {
            tab[j][i] *= scalar;
        }
        return *this;
    }

    Matrix &Matrix::colAdd(int to, int from, double scalar) throw (Wrong_index_exception){
        if (to < 0 || to >= m || from < 0 || from >= m) throw Wrong_index_exception();
        if (scalar == 0) return *this;
        for (int i = 0; i < m; ++i) {
            tab[i][to] += tab[i][from] * scalar;
        }
        return *this;
    }

    Matrix Matrix::rm(int i, int j) throw (Wrong_index_exception){
        if(i<0 || j<0 || i>=n || j>=m)throw Wrong_index_exception();
        Matrix tmp(n-1,m-1);
        for (int k = 0; k < i; ++k) {
            for (int l = 0; l < j; ++l) {
                tmp.tab[i][j] = tab[i][j];
            }
            for (int l = j; l < m-1; ++l) {
                tmp.tab[i][j] = tab[i][j+1];
            }
        }
        for (int k = i; k < n-1; ++k) {
            for (int l = 0; l < j; ++l) {
                tmp.tab[i][j] = tab[i+1][j];
            }
            for (int l = j; l < m-1; ++l) {
                tmp.tab[i][j] = tab[i+1][j+1];
            }
        }
        return tmp;
    }

    double Matrix::det() throw (Not_square_matrix_exception){
        if(n!=m)throw Not_square_matrix_exception();
        Matrix tmp(*this);
        double mult;
        bool minus = false;
        for(int i=0; i<n; i++) {
            if (tmp.tab[i][i] == 0) {
                for (int j = i + 1; j < n; j++)
                    if (tab[j][i] != 0) {
                        tmp.rowSwap(j, i);
                        minus ^= ((j - i) % 2);
                        j = n;
                    }
            }
            if (tmp.tab[i][i] != 0) {
                for (int j = i + 1; j < n; j++) {
                    mult = tmp.tab[j][i] / tmp.tab[i][i];
                    if (std::abs(mult) > 0.000001) {
                        tmp.rowAdd(j, i, -mult);
                    }
                }
            }
        }
        double det=1.0;
        for(int i=0; i<n; i++) det*=tmp.tab[i][i];
        if(minus)det*=(-1);
        return det;
    }

    Matrix Matrix::rev() throw (Reverse_exception){
        if(std::abs(det()) < 0.000001 )throw Reverse_exception();
        Matrix tmp(*this);
        Matrix rev(n,1.0);
        double mult;
        for(int i=0; i<n; i++){
            if(tmp.tab[i][i]==0){
                for(int j=i+1; j<n; j++) if(tab[j][i]!=0){
                        tmp.rowSwap(j, i);
                        rev.rowSwap(j, i);
                        j=n;
                    }
            }
            if(tmp.tab[i][i]!=0) {
                for (int j = 0; j < n; j++)
                    if (j != i) {
                        mult = tmp.tab[j][i] / tmp.tab[i][i];
                        if (mult != 0.0 and mult != -0.0) {
                            tmp.rowAdd(j, i, -mult);
                            rev.rowAdd(j, i, -mult);
                        }
                    }
                mult = 1 / tmp.tab[i][i];
                tmp.rowMult(i, mult);
                rev.rowMult(i, mult);
            }
        }
        tmp.~Matrix();
        return rev;
    }
}