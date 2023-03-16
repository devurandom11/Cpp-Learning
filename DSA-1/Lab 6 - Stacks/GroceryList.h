#ifndef GROCERYLIST_H
#define GROCERYLIST_H

#include <iostream>
#include <stack>

#include "InsertAtCommand.h"
#include "RemoveLastCommand.h"
#include "SwapCommand.h"
#include "UndoCommand.h"

class GroceryList {
 protected:
  std::vector<std::string> listItems;
  std::stack<UndoCommand*> undoStack;

 public:
  virtual void AddWithUndo(std::string newItemName) {
    listItems.push_back(newItemName);
    undoStack.push(new RemoveLastCommand(&listItems));
  }

  virtual void RemoveAtWithUndo(int removalIndex) {
    // TODO
  }

  virtual void SwapWithUndo(int index1, int index2) {
    std::string temp = listItems.at(index1);
    listItems.at(index1) = listItems.at(index2);
    listItems.at(index2) = temp;
    undoStack.push(new SwapCommand(index1, index2, &listItems));
  }

  virtual void ExecuteUndo() {
    // TODO
    UndoCommand* command = undoStack.top();
    undoStack.pop();
    command->Execute();
    delete command;
  }

  virtual int GetListSize() const { return (int)listItems.size(); }

  virtual int GetUndoStackSize() const { return (int)undoStack.size(); }

  virtual std::vector<std::string> GetVectorCopy() const { return listItems; }

  virtual void Print(std::ostream& outputStream) {
    for (size_t i = 0; i < listItems.size(); i++) {
      outputStream << i << ". " << listItems[i] << std::endl;
    }
  }
};

#endif
