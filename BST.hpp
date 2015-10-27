#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <utility> // for std::pair

/** //TODO: list real name(s) and login name(s) 
 *  // of the author(s) of this assignment
 */
/******
 * Name: 		Vishwanath K R
 * Login Name:	CS100wcd
 */
 
template<typename Data>
class BST {

protected:

  BSTNode<Data>* in;
  /** Pointer to the root of this BST, or nullptr if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;


public:

  /** iterator is an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(NULL), isize(0)  {
  }


  /** Default destructor.
   *  It is virtual, to allow appropriate destruction of subclass objects.
   *  Delete every node in this BST.
   */ //x TODO
  virtual ~BST() {
	  clear();	  
  }

  /** Insert a Data item in the BST.
   *  Return a pair, with the pair's first member set to an
   *  iterator pointing to either the newly inserted element
   *  or to the equivalent element already in the set.
   *  The pair's second element is set to true
   *  if a new element was inserted or false if an
   *  equivalent element already existed.
   */ //x TODO
  virtual std::pair<iterator,bool> insert(const Data& item) {
	  
  	if ( root == NULL ) {
      //cout << "add root node ... " << item << endl;
      BSTNode<Data>* n = new BSTNode<Data>(item);
      root = n;
      iterator i(root);
      std::pair<iterator,bool> p(i,1);
      ++isize;
      return p;
    }
    else {
      //cout << "add other node ... " << key << endl;
      BSTNode<Data>* temp = root;
      BSTNode<Data>* par;
      int lr;
      while(temp!=0){
        if (item<temp->data){
          par=temp;
          temp=temp->left;
          lr=0;
        }
        else if(item>temp->data){
          par=temp;
          temp=temp->right; 
          lr=1; 
        }
        else if(item==temp->data){
          iterator i(temp);
          std::pair<iterator,bool> p(i,0);
          ++isize;
          return p;
        }
      }

      temp=new BSTNode<Data>(item);
      temp->parent=par;
      if (lr==0) par->left=temp;
      else par->right=temp;
      iterator i(temp);
      std::pair<iterator,bool> p(i,1);
      ++isize;
      return p;
    }

  }
  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or the end
   *  iterator if the item is not in the BST.
   */ //x TODO
  iterator find(const Data& item) const {
    BSTNode<Data>* q=root;
    while(q->data != item && q!=0) {
                if(item < q->data)
                        q = q->left;
                else
                        q = q->right;
        }

        return q;  

  }

  
  /** Return the number of items currently in the BST.
   */ //x TODO
  unsigned int size() const {
	  
	  return isize;

  }

  /** Remove all elements from this BST, and destroy them,
   *  leaving this BST with a size of 0.
   */ //x TODO
  void clear() {
	  deleteNode(root);
  }

  /** Return true if the BST is empty, else false.
   */ //x TODO
  bool empty() const {
	  return root==NULL;

  }

  /** Return an iterator pointing to the first item in the BST.
   */ //x TODO
  iterator begin() const {
	  return BSTIterator<Data>(first(root));
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return BSTIterator<Data>(NULL);
  }

private:
  void deleteNode(BSTNode<Data>* leaf)	{
  if ( leaf != NULL ) 
    {
        deleteNode(leaf->left);
        deleteNode(leaf->right);
        delete leaf;
    }
  }
  
  static BSTNode<Data>* first(BSTNode<Data>* node) {
   BSTNode<Data>* temp = node;
   while(temp->left != 0) {
              temp = temp->left;
     }
   return temp; 
  }

 };

#endif //BST_HPP