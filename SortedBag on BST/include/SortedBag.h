#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR

//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111;

class SortedBagIterator;

class Node {
public:
	TComp value;
	Node* leftChild;
	Node* rightChild;
	Node* parent;
	int frequency;

	Node(TComp value, int freq = 1) : value(value), leftChild(nullptr), rightChild(nullptr), frequency(freq), parent(nullptr) {}
    Node() {}
};


class SortedBag {
	friend class SortedBagIterator;

private:
	Node* root;
	Relation relation;
	int length;

public:
	//constructor
	SortedBag(Relation r);

	//adds an element to the sorted bag
	void add(TComp e);

	//removes one occurence of an element from a sorted bag
	//returns true if an eleent was removed, false otherwise (if e was not part of the sorted bag)
	bool remove(TComp e);

	//checks if an element appearch is the sorted bag
	bool search(TComp e) const;

	//returns the number of occurrences for an element in the sorted bag
	int nrOccurrences(TComp e) const;

	//returns the number of elements from the sorted bag
	int size() const;

	//returns an iterator for this sorted bag
	SortedBagIterator iterator() const;

	//checks if the sorted bag is empty
	bool isEmpty() const;

	//destructor
	~SortedBag();
};