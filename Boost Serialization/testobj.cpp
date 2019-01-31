#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <iostream>
#include <cstdlib>
struct employee
{
    int         id;
    int         age;
    employee()
    :id(0),age(0) {}
    employee(int id_,int age_) :id(id_),age(age_) {}

    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & id;
        ar & age;
    }
};
void save(const employee& es)
{
    std::ofstream ofs("data");
    boost::archive::text_oarchive oa(ofs);
    oa << es;
}

void load(employee& es)
{
    std::ifstream ifs("data");
    boost::archive::text_iarchive ia(ifs);
    ia >> es;
}

int main()
{
    employee e1(10,20);
    save(e1);
    employee e2;
    load(e2);
    return 0;
}

