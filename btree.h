/* Filename: btree.h
 * -----------------
 * Template class for unbalanced binary tree with no duplicates.
 *
 * Can only be used for values of types with < and << defined. 
 */

#ifndef _btree_h
#define _btree_h

#include <iostream>

template <class T>
class BTree
{
   private:
      struct TreeNode {
         T value;
         TreeNode *left, *right;
      };

      typedef TreeNode * TreePtr;

      TreePtr root;

      bool insert_it(TreePtr &, const T &);
      bool find_it(TreePtr, const T &) const;
      void display_inorder(TreePtr)    const;
      int  get_height(TreePtr)         const;
      void destroy(TreePtr &);

   public:
      BTree() { root = NULL; }
     ~BTree() { destroy(root); }
      bool insert(const T & v)       { return insert_it(root, v); }
      bool search(const T & v) const { return find_it(root, v); }
      void inorder()           const { display_inorder(root); }
      int  height()            const { return get_height(root); }
};


template <class T>
void BTree<T>::destroy(TreePtr & root)
{
   if (root == NULL) return;
   destroy(root->left);
   destroy(root->right);
   delete root;
   root = NULL;
}


template <class T>
bool BTree<T>::insert_it(TreePtr & nodePtr, const T & v)
{
   if (nodePtr == NULL)
   {
      nodePtr = new TreeNode;
      if (nodePtr == NULL) return false;
      nodePtr->left = nodePtr->right = NULL;
      nodePtr->value = v;
      return true;
   }
   else if (v == nodePtr->value) return true;           // already in the tree
   else if (v < nodePtr->value)  return insert_it(nodePtr->left, v);
   return insert_it(nodePtr->right, v);
}


template <class T>
bool BTree<T>::find_it(TreePtr nodePtr, const T & v) const
{
   if (nodePtr == NULL)     return false;
   if (v == nodePtr->value) return true;
   if (v < nodePtr->value)  return find_it(nodePtr->left, v);
   return find_it(nodePtr->right, v);
}


template <class T>
void BTree<T>::display_inorder(TreePtr nodePtr) const
{
   if (nodePtr != NULL)
   {
      display_inorder(nodePtr->left);
      cout << nodePtr->value << " ";
      display_inorder(nodePtr->right);
   }
}


template <class T>
int BTree<T>::get_height(TreePtr nodePtr) const
{
   int h1, h2;
   if (nodePtr == NULL) return 0;
   h1 = get_height(nodePtr->left);
   h2 = get_height(nodePtr->right);
   if (h1 > h2) return 1 + h1;
   else return 1 + h2;
}

#endif
