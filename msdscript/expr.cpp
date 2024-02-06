//
// Created by Aiden Pratt on 1/16/24.
//
#include "expr.h"
#include "catch.h"
#include <utility>
#include <stdexcept>
#include <iostream>
#include <sstream>

/**
 * \file expr.cpp
 * \brief contains expression class and children classes: num, add, mult, var
 */

//---------------EXPR---------------//
/**
* \brief Calculates distance between two points
* \param expr *e argument to check equals with
*/
bool expr::equals(expr *e) {
    return false;
}

/**
 *
 * @return
 */
int expr::interp() {
    return 0;
}

//-------------NUM---------------//
Num :: Num(int val){
    this->val = val;
}
/**
 *
 * @param e
 * @return
 */
bool Num::equals(expr *e) {
    Num *n = dynamic_cast<Num*>(e);
    if(n == nullptr){
        return false;
    }
    else{
        return this->val == n->val;
    }
}
/**
 *
 * @return
 */
int Num::interp() {
    return val;
}
/**
 *
 * @return
 */
bool Num::has_variable() {
    return false;
}
/**
 *
 * @param string
 * @param e
 * @return
 */
expr* Num::subst(std::string string, expr *e) {
    return new Num(this->val);
}
/**
 *
 * @param ostream
 */
void Num::print(std::ostream &ostream) {
    ostream << this->val;
}

/**
 *
 * @param ostream
 * @param p
 */
void Num::pretty_print(std::ostream &ostream, precedence_t p) {
    ostream << this->val;
    //call print
}

//-----------ADD--------------//

/**
 *
 * @param lhs
 * @param rhs
 */
Add :: Add(expr *lhs, expr *rhs){
    this->lhs = lhs;
    this->rhs = rhs;
}
/**
 *
 * @param e
 * @return
 */
bool Add::equals(expr *e) {
    Add *a = dynamic_cast<Add*>(e);
    if(a == nullptr){
        return false;
    }
    else{
        return (lhs->equals(a->lhs)) && (rhs->equals(a->rhs));
    }
}
/**
 *
 * @return
 */
int Add::interp(){
    return this->lhs->interp() + this->rhs->interp();
}

bool Add::has_variable() {
    return this->lhs->has_variable() || this->rhs->has_variable();
}

expr* Add::subst(std::string string, expr *e) {
    return(new Add(this->lhs->subst(string, e),(this->rhs->subst(string,e))));
}

void Add::print(std::ostream &ostream) {
    ostream << "(";
    (this->lhs->print(ostream));
    ostream << "+";
    (this->rhs->print(ostream));
    ostream << ")";
}

void Add::pretty_print(std::ostream &ostream, precedence_t p) {
    if(p > prec_add){
        ostream << "(";
    }

    (this->lhs->pretty_print(ostream, prec_add));
    ostream << " + ";
    (this->rhs->pretty_print(ostream, prec_add));

    if(p > prec_add){
        ostream << ")";
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

int Mult::interp(){
    return this->lhs->interp() * this->rhs->interp();
}

bool Mult::has_variable() {
    return this->lhs->has_variable() || this->rhs->has_variable();
}

expr* Mult::subst(std::string string, expr *e) {
    return(new Mult(this->lhs->subst(string, e),(this->rhs->subst(string,e))));
}

void Mult::print(std::ostream &ostream) {
    ostream << "(";
    (this->lhs->print(ostream));
    ostream << "*";
    (this->rhs->print(ostream));
    ostream << ")";
}


void Mult::pretty_print(std::ostream &ostream, precedence_t p) {

    if(p > prec_mult){
        ostream << "(";
    }
        (this->lhs->pretty_print(ostream, static_cast<precedence_t>(prec_mult + 1)));
        ostream << " * ";
        (this->rhs->pretty_print(ostream, prec_mult));

    if(p > prec_mult){
        ostream << ")";
    }
}
//--------------VAR---------------//

Var :: Var(std::string var) {
    this->var = var;
}

bool Var::equals(expr *e) {
    Var *v = dynamic_cast<Var*>(e);
    if(v == nullptr){
        return false;
    }
    else{
        return this->var == v->var;
    }
}

int Var::interp(){
    throw std::runtime_error("no value for variable");
}

bool Var::has_variable() {
    return true;
}

expr* Var::subst(std::string string, expr *e) {
    if(this->var == string){
        return e;
    }
//    return this;
//returning a new object
    return new Var(this->var);
}

void Var::print(std::ostream &ostream) {
    ostream << this->var;
}


void Var::pretty_print(std::ostream &ostream, precedence_t p) {
    ostream << this->var;
}

