#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP

#include "BSTNode.hpp"
#include <list>
#include <iterator>

/** //TODO: list real name(s) and login name(s) 
 *  // of the author(s) of this assignment
 */

// declare BST here, so friend declaration below will work.
template<typename X> class BST;

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr; // pointer to this BSTIterator's current BSTNode

  /** Constructor.  Use the argument to initialize a given BSTNode
   *  in this BSTIterator.
   *  Note: this constructor is private; but friend classes can access.
   */ // TODO
  BSTIterator(BSTNode<Data>* n) :curr(n) {

  }

public:
  // make BST a friend class, so BST can create a BSTIterator when needed.
  friend class BST<Data>;
  // make BSTNode a friend class, so BSTNode can access curr member variable.
  friend class BSTNode<Data>;


  /** Dereference operator.
   *  Return a copy of the Data item in the current BSTNode.
   */
  Data& operator*() const {
    return this->curr->data;
  }
  
  /** Pre-increment operator.
   *  Update this BSTIterator to point to the inorder successor of the current
   *  BSTNode, and return a reference to the updated BSTIterator.
   */
  BSTIterator<Data>& operator++() {
    BSTIterator<Data> now(curr->successor());
    *this=now;
    return *this;
  }

  /** Post-increment operator. 
   *  Update this BSTIterator to point to the inorder successor of the current
   *  BSTNode, and return a copy of the old, non-updated BSTIterator.
   */
  BSTIterator<Data> operator++(int) {
    BSTIterator<Data> before(curr);
    BSTIterator<Data> now(curr->successor());
    *this=now;
    return before;
  }

  /** Equality test operator. */ // TODO
  bool operator==(BSTIterator<Data> const & other) const {
	return this->curr == other.curr;   
  }

  /** Inequality test operator. */ // TODO
  bool operator!=(BSTIterator<Data> const & other) const {
	return this->curr != other.curr;    
  }

};

#endif //BSTITERATOR_HPP