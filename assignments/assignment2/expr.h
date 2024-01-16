//
// Created by Aiden Pratt on 1/16/24.
//

#ifndef ASSIGNMENT2_EXPR_H
#define ASSIGNMENT2_EXPR_H


#include <string>

class expr {

    virtual bool equals(expr *e) = 0;//each subclass must override
};


class Num : public expr {
public:
    int val;

    explicit Num(int val);

    bool equals(expr *e) override;

};


class Add : public expr{
public:
    expr *lhs;
    expr *rhs;

    Add(expr *lhs, expr *rhs);

    bool equals(expr *e) override;

};

class Mult : public expr {
public:
    expr *lhs;
    expr *rhs;

    Mult(expr *lhs, expr *rhs);

    bool equals(expr *e) override;

};

class Var : public expr{
public:
    std::string val;

    explicit Var(std::string val);

    bool equals(expr *e) override;

};

#endif //ASSIGNMENT2_EXPR_H
