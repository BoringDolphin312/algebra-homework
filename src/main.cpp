#include <iostream>
#include <main.hpp>
#include <calculus.h>

int main(int argc, char **argv){

    //Conjuntos para testes
    math::Conjunto<int> conj_universe({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});

    math::Conjunto<int> integer_conj_1({1, 2, 3, 4});
    math::Conjunto<int> integer_conj_2({3, 4, 5, 6});

    std::cout << "\n=============Conjuntos=================\n";

    std::cout << "Conj1: ";
    integer_conj_1.print();
    std::cout << "Conj2: ";
    integer_conj_2.print();
    std::cout << "Conjunto Universo: ";
    conj_universe.print();

    std::cout << "\n=============União=====================\n";

    //Teste de união
    auto test_union = integer_conj_1.get_union(integer_conj_2);
    std::cout << "Uniao Conj1 e Conj2: ";
    test_union.print();

    std::cout << "\n=============Interseção================\n";

    //Teste de interseção
    auto test_intersec = integer_conj_1.get_intersection(integer_conj_2);
    std::cout << "Interseção Conj1 e Conj2: ";
    test_intersec.print();

    std::cout << "\n=============Complementos==============\n";

    //Teste de complemento
    auto test_complement_1 = integer_conj_1.get_complement(conj_universe);
    auto test_complement_2 = integer_conj_2.get_complement(conj_universe);

    std::cout << "Complemento Conj1 no Conjunto Universo: ";
    test_complement_1.print();
    std::cout << "Complemento Conj2 no Conjunto Universo: ";
    test_complement_2.print();

    std::cout << "\n=============Fim=======================\n";

    return 0;
}

