#include <iostream>
using namespace std;

class BinaryTree
{
private:
    string Value;
    BinaryTree *leftChild;
    BinaryTree *rightChild;

public:
    BinaryTree(string Value);
    ~BinaryTree();
    BinaryTree *createLeft(string Value);
    BinaryTree *createRight(string Value);
    BinaryTree *getLeft();
    BinaryTree *getRight();
    void printOffseted(int depth = 0);
    int findDepth();
    void growTree();
    void growTreeDepth(int depth);
};

BinaryTree ::BinaryTree(string Value)
{
    this->Value = Value;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

BinaryTree ::~BinaryTree()
{
    if (this->leftChild != nullptr)
    {
        delete this->leftChild;
        this->leftChild = nullptr;
    }

    if (this->rightChild != nullptr)
    {
        delete this->rightChild;
        this->rightChild = nullptr;
    }
}

BinaryTree *BinaryTree::createLeft(std::string Value)
{
    if (this->leftChild != nullptr)
        delete this->leftChild;
    this->leftChild = new BinaryTree(Value);
    return this->leftChild;
}

BinaryTree *BinaryTree::createRight(std::string Value)
{
    if (this->rightChild != nullptr)
        delete this->rightChild;
    this->rightChild = new BinaryTree(Value);
    return this->rightChild;
}

BinaryTree *BinaryTree::getLeft()
{
    return this->leftChild;
}
BinaryTree *BinaryTree::getRight()
{
    return this->rightChild;
}

void BinaryTree::printOffseted(int depth)
{
    if (rightChild != nullptr)
        rightChild->printOffseted(depth + 1);

    for (int i = 0; i < depth * 2; ++i)
        cout << "\t";
    cout << Value << endl;

    if (leftChild != nullptr)
        leftChild->printOffseted(depth + 1);
}

int BinaryTree::findDepth()
{
    if (this == nullptr)
        return 0;

    return 1 + max(leftChild->findDepth(), rightChild->findDepth());
}

void BinaryTree::growTree()
{
    if (this->leftChild == nullptr)
        this->leftChild = new BinaryTree("LEFT_leaf");
    else
        leftChild->growTree();

    if (this->rightChild == nullptr)
        this->rightChild = new BinaryTree("RIGHT_leaf");
    else
        rightChild->growTree();
}

void BinaryTree::growTreeDepth(int depth)
{
    for (int i = 0; i < depth; ++i)
    {
        this->growTree();
    }
}

int main()
{
    BinaryTree *bt1 = new BinaryTree("test1");
    bt1->createLeft("newLeft");
    bt1->createRight("newRight");
    bt1->getLeft()->createLeft("newLeft1");
    bt1->getLeft()->createRight("newRight1");
    bt1->getLeft()->getRight()->createLeft("newLeft2");
    bt1->getRight()->createRight("newRight1");
    bt1->getRight()->createLeft("newLeft2");
    bt1->getRight()->getRight()->createRight("newRight2");
    bt1->growTreeDepth(2);
    cout << bt1->findDepth() << endl;

    bt1->printOffseted();

    return 0;
}