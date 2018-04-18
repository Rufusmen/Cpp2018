//
// Created by rufus on 17.04.18.
//

#ifndef CPP2018_MATRIX_H
#define CPP2018_MATRIX_H

#include <iostream>
#include "Invalid_size_exception.h"
#include "Wrong_index_exception.h"
#include "Not_square_matrix_exception.h"
#include "Reverse_exception.h"

namespace calc {
    class Matrix {
    private:
        int n, m;
        double **tab;
    public:
        Matrix(int size, double var=1.0);

        Matrix(int n, int m) throw(Invalid_size_exception);

        Matrix(const Matrix &matrix);

        Matrix(Matrix &&matrix) noexcept;

        Matrix &operator=(const Matrix &matrix);

        Matrix &operator=(Matrix &&matrix) noexcept ;

        ~Matrix();

        friend std::istream &operator>>(std::istream &we, Matrix &matrix);
        friend std::ostream &operator<<(std::ostream &wy, const Matrix &matrix);

        Matrix operator*(double scalar) const;
        Matrix operator~();
        Matrix &operator+=(const Matrix &matrix) throw(Invalid_size_exception);
        Matrix &operator*=(const Matrix &matrix) throw(Invalid_size_exception);
        Matrix &operator-=(const Matrix &matrix) throw(Invalid_size_exception);
        friend Matrix operator+(const Matrix &m1, const Matrix &m2) throw(Invalid_size_exception);

        friend Matrix operator-(const Matrix &m1, const Matrix &m2) throw(Invalid_size_exception);

        friend Matrix operator*(double scalar, const Matrix &matrix) ;
        friend Matrix operator*(const Matrix &m1, const Matrix &m2) throw(Invalid_size_exception);

    private:
        Matrix &rowSwap(int i, int j) throw(Wrong_index_exception);

        Matrix &rowMult(int i, double scalar)throw(Wrong_index_exception);

        Matrix &rowAdd(int to, int from, double scalar)throw(Wrong_index_exception);

        Matrix &colSwap(int i, int j)throw(Wrong_index_exception);

        Matrix &colMult(int i, double scalar)throw(Wrong_index_exception);

        Matrix &colAdd(int to, int from, double scalar)throw(Wrong_index_exception);

        Matrix rm(int i,int j)throw(Wrong_index_exception);

    public:
        double det() throw(Not_square_matrix_exception);

        Matrix rev() throw(Reverse_exception);
    };

}
#endif //CPP2018_MATRIX_H
