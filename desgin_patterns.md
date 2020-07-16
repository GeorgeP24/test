# Factory patterns
## 功能
1. 定义创建对象的接口，封装创建对象的借口。
2. 实例化类的工作延迟到子类进行。
![](/desgin_patterns/factory1_img.png)
![](/desgin_patterns/factory2_img.png)
    将创建类延迟到子类进行。
## 示例
```c++
//.h
class product{
    
    protected:
        product();

    public:
        virtual ~product() = 0;
    
};

class concrete_product:public product{
    public:
        concrete_product();
        ~concrete_product();
};

class factory{
    protected:
        factory();

    public:
        virtual ~factory() = 0;
        virtual product* create_product() = 0;
};

class concrete_factory:public factory{
    public:
        concrete_factory();
        ~concrete_factory();
        product* create_product();

};
//.cpp
//...
product* concrete_factory::create_product(){
    return new concrete_product();
}
//...
//main.cpp
factory* f = new concrete_factory();
product* p = f->create_product();

```

# abstractfactory
## 功能
    为多个存在相关或依赖的对象创建提供接口。
![](/desgin_patterns/abstract_factory_img.png)
## 示例
```c++
//.h
class abstract_productA{
        public:
            virtual ~abstract_productA() = 0;
        protected:
            abstract_productA();
    };
    
    class productA1 : public abstract_productA{
        public:
            productA1();
            ~productA1();
    };

    class productA2 : public abstract_productA{
        public:
            productA2();
            ~productA2();
    };

    class abstract_productB{
        public:
            virtual ~abstract_productB() = 0;
        protected:
            abstract_productB();
    };
    
    class productB1 : public abstract_productB{
        public:
            productB1();
            ~productB1();
    };

    class productB2 : public abstract_productB{
        public:
            productB2();
            ~productB2();
    };

    class abstract_factory{
        public:
            virtual ~abstract_factory() = 0;
            virtual abstract_productA* create_productA() = 0;
            virtual abstract_productB* create_productB() = 0;
        protected:
            abstract_factory();
    };


    class concrete_factory1 : public abstract_factory{
        public:
            concrete_factory1();
            ~concrete_factory1();
            abstract_productA* create_productA();
            abstract_productB* create_productB();
    };

     class concrete_factory2 : public abstract_factory{
        public:
            concrete_factory2();
            ~concrete_factory2();
            abstract_productA* create_productA();
            abstract_productB* create_productB();
    };
//.cpp
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
//main.cpp
abstract_factory* f1 = new concrete_factory1();
    f1->create_productA();
    f1->create_productB();

abstract_factory* f2 = new concrete_factory2();
    f2->create_productA();
    f2->create_productB();
```
# singleton
## 功能
1. 创建维护唯一实例对象。
![](/desgin_patterns/singleton_img.png)
## 示例
```c++
//.h
class singleton{
        public:
            static singleton* instance();
        protected:
            singleton();
        private:
            static singleton* instance_;
    };
//.cpp
singleton* singleton::instance_ = nullptr;
    singleton* singleton::instance(){
        if(instance_ == nullptr)
            return new singleton();
        return instance_;
    }
//main.cpp
```
# builder 
## 功能
1. 分离复杂对象的创建过程和对象本身。
2. 流程化复杂对象创建过程。
![](/desgin_patterns/builder_img.png)
## 示例
```c++
//.h
class product{
        public:
            void set_partA(const string& para);
            void set_partB(const string& para);
            void set_partC(const string& para);
            void set_partD(const string& para);
            product();
            ~product();
        private:
            string partA_;
            string partB_;
            string partC_;
            string partD_;
    };

    
    
    class builder{
        public:
            virtual void build_partA(const string& para) = 0;
            virtual void build_partB(const string& para) = 0;
            virtual void build_partC(const string& para) = 0;
            virtual void build_partD(const string& para) = 0;
            virtual product* get_product() = 0;
            virtual ~builder();
            builder();
    };

    class concrete_builder: public builder{
        public:
            concrete_builder():product_(new product){};
            ~concrete_builder();
            void build_partA(const string& para);
            void build_partB(const string& para);
            void build_partC(const string& para);
            void build_partD(const string& para);
            product* get_product();  
        private:
            product* product_;          
    };

    class director{
        public:
            director(builder* bld):bld_(bld){};
            ~director();
            void construct();
        private:
            builder* bld_;
    };
//.cpp
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
//main.cpp
director* f = new director(new builder());
f->construct();
```

# prototype
## 功能
1. 提供自我复制功能，新对象创建通过对已有对象进行复制。
![](/desgin_patterns/prototype_img.png)
## 示例
```c++
//.h
class prototype{
        public:
            virtual ~prototype();
            virtual prototype* clone() const = 0;
        protected:
            prototype();
    };
    
    class concrete_prototype : public prototype{
        public:
            concrete_prototype();
            concrete_prototype(const prototype&);
            ~concrete_prototype();
            prototype* clone() const;
    };
//.cpp
prototype* concrete_prototype::clone() const{
        return new concrete_prototype(*this);
    }
```

# bridge
## 功能
1. 控制类的高速膨胀。
2. 抽象和实现的分离。
3. 封装细节。
![](/design_patterns/bridge_img.png)
## 示例