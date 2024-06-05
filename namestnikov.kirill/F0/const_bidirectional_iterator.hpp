#ifndef CONST_BIDIRECTIONAL_ITERATOR_HPP
#define CONST_BIDIRECTIONAL_ITERATOR_HPP

#include <iterator>
#include "bidirectional_node.hpp"

namespace namestnikov
{
  template< class T >
  class List;

  template< class T >
  class ConstListIterator: public std::iterator< std::bidirectional_iterator_tag, T >
  {
    friend class List< T >;
  public:
    using node_t = detail::BaseListNode;
    using const_iterator = ConstListIterator< T >;
    ConstListIterator():
      node_(nullptr)
    {}
    ConstListIterator(const const_iterator &) = default;
    const_iterator & operator(const const_iterator &) = default;
    ConstListIterator(const_iterator &&) = default;
    bool operator==(const const_iterator & other) const
    {
      return (node_ == other.node_);
    }
    bool operator!=(const const_iterator & other) const
    {
      return !(*this == other);
    }
    const T & operator*() const
    {
      return (dynamic_cast< const detail::BiListNode< T > * >(node_))->data;
    }
    const T * operator->() const
    {
      return std::addressof(**this);
    }
    const_iterator & operator++()
    {
      node_ = node_->next;
      return *this;
    }
    const_iterator operator++(int)
    {
      const_iterator temp(*this);
      ++(*this);
      return temp;
    }
    const_iterator & operator--()
    {
      node_ = node_->prev;
      return *this;
    }
    const_iterator operator--(int)
    {
      const_iterator temp(*this);
      --(*this);
      return temp;
    }
  private:
    const node_t * node_;
    explicit ConstListIterator(node_t * node):
      node_(node)
    {}
  };
}

#endif