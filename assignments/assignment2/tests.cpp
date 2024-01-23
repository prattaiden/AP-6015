#include "catch.h"
#include "expr.h"

TEST_CASE("Nabil_Test_Cases"){
    CHECK( (new Var("x"))->equals(new Var("x")) == true );
    CHECK( (new Var("x"))->equals(new Var("y")) == false );
    CHECK( (new Num(1))->equals(new Var("x")) == false );
    CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(3),new Num(2)))==false );
    CHECK( (new Add(new Num(2),new Num(3)))->equals(new Add(new Num(2),new Num(3)))==true );
}

//
TEST_CASE("Test_Mult"){
    CHECK((new Mult(new Num (4), new Num(10)))->equals(new Mult(new Num (4), new Num(10))) == true);
    CHECK( (new Mult(new Num(2),new Num(3)))->equals(new Mult(new Num(3),new Num(2)))==false);
    //testing that casting the mult on the add will just be false
    CHECK((new Mult(new Num(2),new Num(3)))->equals(new Add(new Num(3),new Num(2)))==false);
    //testing when plugging a Var in instead of a Num
    CHECK((new Mult(new Var("2"),new Var("3")))->equals(new Mult(new Var("3"),new Var("2")))==false);
    CHECK((new Mult(new Var("2"),new Var("3")))->equals(new Mult(new Var("2"),new Var("3")))==true);
}

TEST_CASE("Test_Num"){
    CHECK((new Num(5))->equals((new Num (5)))== true);
    CHECK((new Num(6))->equals((new Num (2)))== false);
    //testing casting var and num will be false
    CHECK((new Num(6))->equals((new Var ("6")))== false);

}

TEST_CASE("Test_Var"){
    CHECK((new Var("f"))->equals((new Var ("f")))== true);
    CHECK((new Var("v"))->equals((new Var ("r")))== false);
    //testing casting Num and Var will be false
    CHECK((new Var("6"))->equals((new Num (6)))== false);
    CHECK((new Var("6"))->equals((new Var ("6")))== true);
}


TEST_CASE("TEST_Interp_Nabil"){
    CHECK_THROWS_WITH( (new Var("x"))->interp(), "no value for variable" );
    CHECK( (new Mult(new Num(3), new Num(2)))->interp()==6 );
    CHECK( (new Add(new Add(new Num(10), new Num(15)),new Add(new Num(20),new Num(20))))->interp()==65);
}

TEST_CASE("Test_has_variable"){
    CHECK((new Add(new Var("x"), new Num(3)))->has_variable() == true);
    CHECK((new Add(new Num(5), new Num(5)))->has_variable() == false);
    CHECK( (new Add(new Add(new Num(10), new Var("y")),new Add(new Num(20),new Num(20))))->has_variable()==true);
}

TEST_CASE("Test_subst_Nabil"){
    CHECK( (new Add(new Var("x"), new Num(7)))->subst("x", new Var("y"))->equals(new Add(new Var("y"), new Num(7))) );
    CHECK( (new Var("x"))->subst("x", new Add(new Var("y"),new Num(7)))->equals(new Add(new Var("y"),new Num(7))) );
}
