#include <memory>
#include <iostream>
#include <vector>

class Abstract
{
public:
	virtual void pr() = 0;
	virtual ~Abstract() {std::cout<<"~Abstract"<<std::endl;};
};

class Concrete : public Abstract
{
public:
	void pr() override { std::cout<<"Concrete pr@"<<this<<std::endl;}
	~Concrete() {std::cout<<"~Concrete"<<std::endl;}

};

class CompositeAbstract : public Abstract
{
public:
	void add(std::unique_ptr<Abstract> a) {
		compositeList_.push_back(std::move(a));
	}
	void pr() override {
		for (std::vector<std::unique_ptr<Abstract>>::iterator i = compositeList_.begin(); i != compositeList_.end(); i++) {
			std::cout<<"in CompositeAbstract:@"<<this<<";";
			(*i)->pr();
			std::cout<<std::endl;
		}
	}
private:
	std::vector<std::unique_ptr<Abstract>> compositeList_;
};
void func(std::unique_ptr<Abstract> a) {
	std::cout<<"in func a@"<<(a).get()<<std::endl;
	(a)->pr();
}


int main(int argc, char const *argv[])
{
	
	std::unique_ptr<Concrete> c = std::make_unique<Concrete>();
	std::cout<<"in main c@"<<c.get()<<std::endl;
	// std::unique_ptr<Abstract> a = std::make_unique<Abstract>();
	func(std::move(c));
	// func(&c);


	std::unique_ptr<Concrete> c1 = std::make_unique<Concrete>();
	std::unique_ptr<Concrete> c2 = std::make_unique<Concrete>();
	std::unique_ptr<Concrete> c3 = std::make_unique<Concrete>();

	std::cout<<"Concrete unique_ptrs:"<<c1.get()<<","<<c2.get()<<","<<c3.get()<<std::endl;
	CompositeAbstract ca; 
	ca.add(std::move(c1));
	ca.add(std::move(c2));
	ca.add(std::move(c3));
	ca.pr();

	([](){std::cout<<std::endl;for(int k=0;k<64;k++){std::cout<<"=";} std::cout<<std::endl;})();

	std::unique_ptr<Concrete> d1 = std::make_unique<Concrete>();
	std::unique_ptr<Concrete> d2 = std::make_unique<Concrete>();
	std::unique_ptr<Concrete> d3 = std::make_unique<Concrete>();
	std::unique_ptr<Concrete> d4 = std::make_unique<Concrete>();

	std::unique_ptr<CompositeAbstract> com1 = std::make_unique<CompositeAbstract>();
	std::unique_ptr<CompositeAbstract> com2 = std::make_unique<CompositeAbstract>();

	std::unique_ptr<CompositeAbstract> comBig = std::make_unique<CompositeAbstract>();


	std::cout
	<<"d1@"<<d1.get()<<";"
	<<"d2@"<<d2.get()<<";"
	<<"d3@"<<d3.get()<<";"
	<<"d4@"<<d4.get()<<";"
	<<std::endl
	<<"com1@"<<com1.get()<<";"
	<<"com2@"<<com2.get()<<";"
	<<"comBig@"<<comBig.get()<<";"
	<<std::endl;

	com1->add(std::move(d1));
	com1->add(std::move(d2));

	com2->add(std::move(d3));
	com2->add(std::move(d4));

	

	comBig->add(std::move(com1));
	comBig->add(std::move(com2));





	comBig->pr();




	return 0;
}