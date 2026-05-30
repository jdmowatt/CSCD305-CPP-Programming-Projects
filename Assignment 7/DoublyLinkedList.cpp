#include "Node.h"
#include "Node.cpp"

template <typename T>

void createDoublyLinkedList(T dataOne, T dataTwo, T dataThree) {
	shared_ptr<Node<T>> start;
	weak_ptr<Node<T>> end;

	shared_ptr<Node<T>> nd = make_shared<Node<T>>(dataOne);

	start = nd;
	end = start;

	auto nd1 = make_shared<Node<T>>(dataTwo);

	nd1->setPrevious(end);
	end.lock()->setNext(nd1);
	end = nd1;

	auto nd2 = make_shared<Node<T>>(dataThree);

	nd2->setPrevious(end);
	end.lock()->setNext(nd2);
	end = nd2;

	PrintForward(start);
	PrintReverse(end);


}

int main() {

	createDoublyLinkedList("Tom", "Dick", "Harry");
	cout << endl;
	createDoublyLinkedList(1, 2, 3);

	return 0;
}