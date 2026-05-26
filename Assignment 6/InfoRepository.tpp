template<typename T, typename U, typename V>
InfoRepository<T, U, V>::~InfoRepository() {
    InfoNode<T,U,V>* temp = first;
    while (temp != nullptr) {
        InfoNode<T,U,V>* next = temp->next;
        delete temp;
        temp = next;
    }
}

template<typename T, typename U, typename V>
void InfoRepository<T, U, V>::addInfo(T t, U u, V v) {
    InfoNode<T,U,V>* newNode = new InfoNode<T,U,V>(t, u, v, first);
    first = newNode;
}

template<typename T, typename U, typename V>
bool InfoRepository<T, U, V>::isEmpty() {
    return !first;
}

template<typename T, typename U, typename V>
void InfoRepository<T, U, V>::printInformation() {

    std::cout << "Printing " << iName << " info....." << std::endl << std::endl;
    InfoNode<T,U,V>* temp = first;
    while (temp != nullptr) {
        std::cout << std::fixed << std::setprecision(2)
                << std::left
                << std::setw(20) << temp->dataOne
                << std::setw(30) << temp->dataTwo
                << std::setw(20) << temp->dataThree
                << std::endl;
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T, typename U, typename V>
void InfoRepository<T, U, V>::retrieveInfoNode(const T &t) {
    std::cout << "Retrieving Node with id " << t << " from the database......" << std::endl;

    InfoNode<T,U,V>* temp = first;
    while (temp != nullptr) {
        if (temp->dataOne == t) {
            std::cout << "Node with id " << t << " was found in the database." << std::endl << std::endl;
            std::cout <<  "Here's the information ....." << std::endl;

            std::cout << std::fixed << std::setprecision(2)
                << std::left
                << std::setw(20) << temp->dataOne
                << std::setw(30) << temp->dataTwo
                << std::setw(20) << temp->dataThree
                << std::endl << std::endl;
            return;
        }
        temp = temp->next;
    }

    std::cout << "No Node with id " << t << " exists in the list." << std::endl << std::endl;
}