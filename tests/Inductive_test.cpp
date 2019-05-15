#include <gtest/gtest.h>
#include <Inductive_miner_algorithm.h>
#include <fstream>


Inductive_miner_algorithm* inductiveMinerAlgorithm;

set < Trace*, myClassComp > traces1;

void create_inductive(const string& filename)
{
    ifstream fin("../../tests/resource/" + filename);

    string buff;
    while (fin >> buff)
        traces1.insert(new Trace(buff));
    inductiveMinerAlgorithm = new Inductive_miner_algorithm();
}

void delete_inductive()
{
    for (Trace* trace : traces1)
        delete trace;
    traces1.clear();
    delete inductiveMinerAlgorithm;
}

TEST(inductive_test, test1)
{
    create_inductive("inductive1");
    string res = inductiveMinerAlgorithm->algorithm_B(traces1);
    EXPECT_EQ(">(a,^(b,c))", res);
    delete_inductive();
}



TEST(inductive_test, test2)
{
    create_inductive("inductive2");
    string res = inductiveMinerAlgorithm->algorithm_B(traces1);
    EXPECT_EQ("@(>(d,e),f)", res);
    delete_inductive();
}

TEST(inductive_test, test3)
{
    create_inductive("inductive3");
    string res = inductiveMinerAlgorithm->algorithm_B(traces1);
    EXPECT_EQ(">(a,X(^(b,c),@(>(d,e),f)))", res);
    delete_inductive();
}


TEST(inductive_test, test4)
{
    create_inductive("inductive4");
    string res = inductiveMinerAlgorithm->algorithm_B(traces1);
    EXPECT_EQ("^(>(a,c),^(b,d))", res);
    delete_inductive();
}



TEST(inductive_test, test5)
{
    create_inductive("inductive5");
    string res = inductiveMinerAlgorithm->algorithm_B(traces1);
    EXPECT_EQ(">(a,@(>(^(X(b,c),d),e),f),X(g,h))", res);
    delete_inductive();
}