#include<string>
namespace factory{
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
}

namespace abstract_factory{

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

}

namespace singleton{
    class singleton{
        public:
            static singleton* instance();
        protected:
            singleton();
        private:
            static singleton* instance_;
    };
}

namespace builder{
    using std::string;

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
}

namespace prototype{
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
}