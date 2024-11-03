#ifndef CALCULUS_H
#define CALCULUS_H

#include <initializer_list>
#include <iostream>
#include <vector>
#include <algorithm>

namespace math{
    template <typename T>
    class Conjunto{
        public:
            Conjunto(){
            }

            Conjunto(std::initializer_list<T> initial_list){
                data = initial_list;
            }

            Conjunto get_union(const Conjunto& addition){
                auto copy = addition;
                auto res = Conjunto<T>();

                for(const auto& item : data){
                    auto search = std::find(copy.data.begin(), copy.data.end(), item);
                    if(search != copy.data.end()){
                        copy.data.erase(search);
                    }
                }

                res.data.insert(res.data.end(), data.begin(), data.end());
                res.data.insert(res.data.end(), copy.data.begin(), copy.data.end());

                return res;
            }

            void execute_union(const Conjunto& addition){
                auto r = this->get_union(addition);

                this->data.clear();
                this->data = r.data;
            }

            Conjunto get_intersection(const Conjunto& intersec){
                auto res = Conjunto<T>();

                for(const auto& item : data){
                    auto search = std::find(intersec.data.begin(), intersec.data.end(), item);

                    if(search != intersec.data.end())
                        res.data.push_back(item);
                }

                return res;
            }

            void execute_intersection(const Conjunto& intersec){
                auto r = this->get_intersection(intersec);

                this->data.clear();
                this->data = r.data;
            }

            Conjunto get_complement(const Conjunto& conj_universe){
                auto res = Conjunto<T>();

                for(const auto& item : conj_universe.data){
                    auto search = std::find(data.begin(), data.end(), item);
                    
                    if(search == data.end()){
                        res.data.push_back(item);
                    }
                }

                return res;
            }

            void execute_complement(const Conjunto& conj_universe){
                auto r = this->get_complement(conj_universe);

                this->data.clear();
                this->data = r.data;
            }

            void print(){
                std::cout << "{";
                for(int i = 0; i < data.size(); i++){
                    std::cout << data[i];
                    if(i+1 < data.size())
                        std::cout << ", ";
                }
                std::cout << "}\n";
            }

            std::vector<T> data;
    };
}

#endif
