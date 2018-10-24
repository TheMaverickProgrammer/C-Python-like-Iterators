/*
Author: Maverick Peppers
Date: 10/22/2018
Description: Code additions made from a blog post describing the concept. 
Additions allow the option for just an index value to be used just like python.

Further reading:  https://therocode.net/web/tmpblog/2018/10/for-each-with-index.html

*/

#include <vector>
#include <map>
#include <type_traits>

template <typename container_type>
struct enumerate_wrapper
{
    using iterator_type = std::conditional_t<std::is_const_v<container_type>, typename container_type::const_iterator, typename container_type::iterator>;
    using pointer_type = std::conditional_t<std::is_const_v<container_type>, typename container_type::const_pointer, typename container_type::pointer>;
    using reference_type = std::conditional_t<std::is_const_v<container_type>, typename container_type::const_reference, typename container_type::reference>;

    struct dissolving_pair : public std::pair<size_t, reference_type> {
        dissolving_pair(size_t index, reference_type ref) : std::pair<size_t, reference_type>(index, ref) { ; }
        operator size_t() { return this->first; }
        template<reference_type> reference_type get() { return this->second; }
    };

    enumerate_wrapper(container_type& c): container(c)
    {

    }

    struct enumerate_wrapper_iter
    {
        size_t index;
        iterator_type value;


        bool operator!=(const iterator_type& other) const
        {
            return value != other;
        }
        enumerate_wrapper_iter& operator++()
        {
            ++index;
            ++value;
            return *this;
        }

        dissolving_pair operator*() {
            return dissolving_pair{index, *value};
        }
    };

    enumerate_wrapper_iter begin()
    {
        return {0, container.begin()};
    }

    iterator_type end()
    {
        return container.end();
    }
    container_type& container;
};

template <typename container_type, typename key_type>
struct enumerate_wrapper_map
{
    using iterator_type = std::conditional_t<std::is_const_v<container_type>, typename container_type::const_iterator, typename container_type::iterator>;
    using pointer_type = std::conditional_t<std::is_const_v<container_type>, typename container_type::const_pointer, typename container_type::pointer>;
    using reference_type = std::conditional_t<std::is_const_v<container_type>, typename container_type::const_reference, typename container_type::reference>;

    struct dissolving_map  : public std::pair<size_t, reference_type> {
        dissolving_map(size_t index, reference_type ref) : std::pair<size_t, reference_type>(index, ref) { ; }
        operator key_type() {return this->second.first.data(); }
        operator size_t() { return this->first; }
        template<reference_type> reference_type get() { return this->second; }
    };

    enumerate_wrapper_map(container_type& c): container(c)
    {

    }

    struct enumerate_wrapper_iter
    {
        size_t index;
        iterator_type value;


        bool operator!=(const iterator_type& other) const
        {
            return value != other;
        }
        enumerate_wrapper_iter& operator++()
        {
            ++index;
            ++value;
            return *this;
        }

        dissolving_map operator*() {
            return dissolving_map{index, *value};
        }
    };

    enumerate_wrapper_iter begin()
    {
        return {0, container.begin()};
    }

    iterator_type end()
    {
        return container.end();
    }
    container_type& container;
};

template <typename T, template <typename> class V>
auto enumerate(V<T>& c)
{
    return enumerate_wrapper(c);
}

template<typename T, typename U, template <typename, typename> class V>
auto enumerate(V<T,U>& c)
{
    return enumerate_wrapper_map<V<T,U>, T>(c);
}
