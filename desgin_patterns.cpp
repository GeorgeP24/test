#include"desgin_patterns.h"



namespace factory{
product* concrete_factory::create_product(){
    return new concrete_product();
    }
}

namespace abstract_factory{
    abstract_productA* concrete_factory1::create_productA(){
        return new productA1();
    }
    abstract_productB* concrete_factory1::create_productB(){
        return new productB1();
    }

    abstract_productA* concrete_factory2::create_productA(){
        return new productA2();
    }
    abstract_productB* concrete_factory2::create_productB(){
        return new productB2();
    }
}

namespace singleton{
    singleton* singleton::instance_ = nullptr;
    singleton* singleton::instance(){
        if(instance_ == nullptr)
            return new singleton();
        return instance_;
    }
}

namespace builder{
    void product::set_partA(const string& para){
        this->partA_ = para;
    }
    
    void product::set_partB(const string& para){
        this->partB_ = para;
    }

    void product::set_partC(const string& para){
        this->partC_ = para;
    }

    void product::set_partD(const string& para){
        this->partD_ = para;
    }

    void concrete_builder::build_partA(const string& para){
        //step one;
        this->product_->set_partA("A");
    }
    
    void concrete_builder::build_partB(const string& para){
        //step two;
        this->product_->set_partB("B");
    }
    
    void concrete_builder::build_partC(const string& para){
        //step three;
        this->product_->set_partC("C");
    }
    
    void concrete_builder::build_partD(const string& para){
        //step four;
        this->product_->set_partD("D");
    }

    product* concrete_builder::get_product(){
        return product_;
    }

    concrete_builder::~concrete_builder(){
        delete  product_;
        product_ = nullptr;
    }

    void director::construct(){
        bld_->build_partA("self-define");
        bld_->build_partB("self-define");
        bld_->build_partC("self-define");
        bld_->build_partD("self-define");
    }

    director::~director(){
        delete bld_;
        bld_ = nullptr;
    }
}

namespace prototype{
    prototype* concrete_prototype::clone() const{
        return new concrete_prototype(*this);
    }
}