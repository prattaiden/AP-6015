//
// Created by Aiden Pratt on 1/16/24.
//

#ifndef ASSIGNMENT2_EXPR_H
#define ASSIGNMENT2_EXPR_H


#include <string>

class expr {
public:
    virtual bool equals(expr *e) = 0;//each subclass must override
    virtual int interp() = 0;
    virtual bool has_variable() = 0;
    virtual expr* subst(std::string string , expr *e) = 0;
};

//-----------NUM----------//
class Num : public expr {
public:
    int val;
    explicit Num(int val);
    bool equals(expr *e) override;
    int interp() override;
    bool has_variable() override;
    expr* subst(std::string string , expr *e) override;
};

//----------ADD-----------//
class Add : public expr{
public:
    expr *lhs;
    expr *rhs;
    Add(expr *lhs, expr *rhs);
    bool equals(expr *e) override;
    int interp() override;
    bool has_variable() override;
    expr* subst(std::string string , expr *e) override;
};

//-----------MULT-------//
class Mult : public expr {
public:
    expr *lhs;
    expr *rhs;
    Mult(expr *lhs, expr *rhs);
    bool equals(expr *e) override;
    int interp() override;
    bool has_variable() override;
    expr* subst(std::string string , expr *e) override;
};

//------------VAR----------//
class Var : public expr{
public:
    std::string val;
    Var(std::string val);
    bool equals(expr *e) override;
    int interp() override;
    bool has_variable() override;
    expr* subst(std::string string , expr *e) override;
};

#endif //ASSIGNMENT2_EXPR_H
