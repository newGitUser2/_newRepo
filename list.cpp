#include <iostream>
#include <typeinfo>
#include <cassert>
#include "list.hpp"

//Конструктор по умолчанию, где даны исходные значения переменных классов
List::List(){
  	first = nullptr;
	size = 0;
}

/*Деструктор класса, который сначала удаляет первый Node* списка, затем сохраняет
следующий элемент в качестве первого элемента, снова удаляя его и так до последнего элемента.  */
List::~List(){
      	 Node *tmp_first;
         for(int i = 0; i < size; i++){
        	tmp_first = first->next;
        	delete first;
                first = tmp_first;
       	}
        size -= size;
}

/*Создается массив типа Node*, где перемещаются объекты данного типа и в результате
чего предоставляется возможность обращаться к элементам с оператором индексации.  */
int List::operator[](int index){
      	int size = 3;
    	Node *object = first;
      	Node *array = new Node[size];
     	int i = 0;
       	while(object != nullptr){
       		array[i] = object->data;
                object = object->next;
                i++;
  	}
        return array[index].data;
}

//Переменной с именем size присваивается новое значение
void List::set_size(int num){
	assert(typeid(num).name() == typeid(1).name() &&
		      "As an argument to the function, you must give a number");
	size = num;
}

//Возвращает текущее значение переменной size
int List::get_size(){
	return size;
}

//Предназначен для определения того, существует ли созданный объект типа Node*
bool List::is_empty(){
      	return first == nullptr;
}

//Добавление нового объекта типа Node* в список
void List::insert(int element, int index){
    	if(index > size)
    		std::cout << "Index should be <= " << size << '\n';
    	if(index == size)
     		push_back(element);
  	else{
                Node *prev_node;
                Node *node = first;
                for(int i = 0; i < index; i++){
               		prev_node = node;
              		node = node->next;
            	}
               	Node *new_node = new Node(element, node);
              	prev_node->next = new_node;
      	}
        print();
}

//Добавление нового элемента в конец списка.
void List::push_back(int data){
	try{
		if(typeid(data).name() != typeid(1).name())
			throw "Argument of the function must ne number!";
	}
	catch(const char* exception){
		std::cerr << "Error: " << exception << std::endl;
	}
      	Node *node = new Node(data);
        if(is_empty())
       		first = node;
  	else{
      		Node *tmp = first;
                while(tmp->next != nullptr){
   			tmp = tmp->next;
   		}
                tmp->next = node;
     	}
}

//Возвращает последний элемент списка.
int List::pop_back(){
     	Node *node = first;
        Node *out_node;
        while(node != nullptr){
      		out_node  = node;
                node = node->next;
    	}
        return out_node->data;
}

//Вывод текущего состава объекта типа List
void List::print(){
      	if(is_empty()){
       		std::cout << "We don't have any nodes yet\n";
       	}
     	else{
      		Node *node = first;
             	std::cout << "From method <print>\n";
                while(node != nullptr){
            		std::cout << node->data << " ";
                        node = node->next;
          	}
                std::cout << std::endl;
      	}
}

//Удаляет элемент из списка в соответствии со значением, указанным в качестве параметра.
void List::remove_by_value(int value){
      	//d_node - removable node, p_node - previous node
       	Node *d_node = first;
        Node *p_node;
        while(d_node->data != value){
        	p_node = d_node;
                d_node = d_node->next;
     	}
       	p_node->next = d_node->next;
        delete d_node;
        print();
}

//Удаляет элемент из списка в соответствии с индексом, заданным в качестве параметра.
void List::remove_by_index(int index){
      	Node *node = first;
       	Node *d_node;
        int num = 0;
        while(node != nullptr){
        	if(num == index){
              		d_node = node;
               	}
                node = node->next;
                num++;
      	}
        Node *p_node;
        Node *tmp_node = first;
       	while(tmp_node != d_node){
       		p_node = tmp_node;
                tmp_node = tmp_node->next;
    	}
        p_node->next = d_node->next;
        delete d_node;
       	print();
}
