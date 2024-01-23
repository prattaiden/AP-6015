//
// Created by Aiden Pratt on 1/16/24.
//
#include "expr.h"
#include "catch.h"
#include <utility>

bool expr::equals(expr *e) {
    return false;
}

//-------------NUM---------------//

Num :: Num(int val){
    this->val = val;
}
bool Num::equals(expr *e) {
    Num *n = dynamic_cast<Num*>(e);
    if(n == nullptr){
        return false;
    }
    else{
        return this->val == n->val;
    }
}

//-----------ADD--------------//

Add :: Add(expr *lhs, expr *rhs){
    this->lhs = lhs;
    this->rhs = rhs;

}
bool Add::equals(expr *e) {
    Add *a = dynamic_cast<Add*>(e);
    if(a == nullptr){
        return false;
    }
    else{
        return (lhs->equals(a->lhs)) && (rhs->equals(a->rhs));
    }
}


//-----------MULT----------------\\

Mult :: Mult(expr *lhs, expr *rhs) {
    this->lhs = lhs;
    this->rhs = rhs;
}

bool Mult::equals(expr *e) {
    Mult *m = dynamic_cast<Mult*>(e);
    if(m == nullptr){
        return false;
    }
    else{
        return (lhs->equals(m->lhs)) && ((rhs->equals(m->rhs)));
    }
}

//--------------VAR---------------//

Var :: Var(std::string val) {
    this->val = val;
}

bool Var::equals(expr *e) {
    Var *v = dynamic_cast<Var*>(e);
    if(v == nullptr){
        return false;
    }
    else{
        return this->val == v->val;
    }
}

