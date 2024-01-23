//
// Created by Aiden Pratt on 1/16/24.
//
#include "expr.h"
#include "catch.h"
#include <utility>
#include <stdexcept>

//---------------EXPR---------------//
bool expr::equals(expr *e) {
    return false;
}
int expr::interp() {
    return 0;
}
expr* subst(std::string string, expr* e){
    return e;
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
int Num::interp() {
    return val;
}
bool Num::has_variable() {
    return false;
}
expr* Num::subst(std::string string, expr *e) {
    return this;
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

int Add::interp(){
    return this->lhs->interp() + this->rhs->interp();
}

bool Add::has_variable() {
    return this->lhs->has_variable() || this->rhs->has_variable();
}

expr* Add::subst(std::string string, expr *e) {
    return(new Add(this->lhs->subst(string, e),(this->rhs->subst(string,e))));
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

int Mult::interp(){
    return this->lhs->interp() * this->rhs->interp();
}

bool Mult::has_variable() {
    return this->lhs->has_variable() || this->rhs->has_variable();
}

expr* Mult::subst(std::string string, expr *e) {
    return(new Mult(this->lhs->subst(string, e),(this->rhs->subst(string,e))));
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

int Var::interp(){
    throw std::runtime_error("no value for variable");
}

bool Var::has_variable() {
    return true;
}

expr* Var::subst(std::string string, expr *e) {
    if(this->val == string){
        return e;
    }
    return this;
}

