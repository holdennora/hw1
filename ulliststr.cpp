#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
std::string const & ULListStr::front() const
{
  if(empty())
  {
    throw std::out_of_range("front on an empy list");
  }
  return head_->val[head_->first];
}
std::string const & ULListStr::back() const
{
  if(empty())
  {
    throw std::out_of_range("back on an empy list");
  }
  return tail_->val[tail_->last-1];
}

void ULListStr::pop_front()
{
  if (empty())
  {
    return;
  }
  head_->first++;
  size_--;
  if(head_->first == head_ ->last)
  {
    Item* temp = head_->next;
    delete head_;
    head_ = temp;

    if(head_ != nullptr)
    {
      head_->prev = nullptr;
      tail_ = nullptr;
    }
    else
    {
      tail_ = nullptr;
    }
  }
}

  
void ULListStr::pop_back()
{
  if (empty())
  {
    return;
  }
  else if (tail_ != NULL)
  {
    tail_->last--;
    size_ --;

    if (tail_ -> last == tail_->first)
    {
      Item* temp = tail_-> prev;
      delete tail_;
      tail_ = temp;

      if (tail_ != NULL)
      {
        tail_->next = NULL;
      }
      else
      {
        head_ = NULL;
      }
    } 
  }
}
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_)
  {
    return nullptr;
  }

  size_t counter = 0;
  Item* curr = head_;

  while ( curr != nullptr && counter + (curr -> last - curr-> first) <= loc)
  {
    counter += curr->last - curr->first;
    curr = curr-> next;
  }
  if (curr == nullptr)
  {
    return nullptr;
  }

  size_t offset = loc - counter;

  if (offset >= ARRSIZE && offset < ARRSIZE)
  {
    return nullptr;
  }

  return &(curr -> val[offset+curr->first]);
}

void ULListStr::push_back(const std::string& val)
{
  if (empty() || tail_ ->last == ARRSIZE)
  {
    Item* newNode = new Item();
    newNode->prev = tail_;
    newNode->next = NULL;

    if (tail_ != NULL)
    {
      tail_ ->next = newNode;
    }
    else
    {
      head_ = newNode;
    }
    tail_ = newNode;
  }

  tail_->val[tail_->last++] = val;
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  if (empty() || head_ ->first == 0)
  {
    Item* newNode = new Item();
    newNode->prev = NULL;
    newNode->next = head_;
    newNode->first = ARRSIZE;
    newNode->last = ARRSIZE;

    if (head_ != NULL)
    {
      head_->prev = newNode;
    }
    else
    {
      tail_ = newNode;
    }

    head_ = newNode;
  }
  
  head_->val[--head_->first] = val;
  size_++;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
