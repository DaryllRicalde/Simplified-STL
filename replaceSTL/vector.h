#pragma once

namespace std{
    template <typename T>
    class vector {
        private:
            T* arr;
            static const size_t INITIAL_CAPACITY = 10;  // initial capacity of the array  
            size_t space;                               // space used by vector including elements and free space
            size_t size;                                // the current number of items in the array
        public:
            /* Types */
            using value_type            = T;
            using reference             = value_type&;
            using const_reference       = const value_type&;
            using size_type             = size_t;

            struct iterator
            {
                using value_type = T;
                using pointer = T*; 
                using reference = T&;

                iterator(pointer ptr) : curr(ptr) {}

                pointer operator->() { return curr; }
                reference operator*() {return curr; }
                iterator& operator++() { curr++; return *this; }
                /** Postfix increment operator
                 * @return A copy of this iterator before being advanced 
                 */
                iterator operator++(int)
                {
                    iterator return_val = *this;
                    ++(*this);
                    return return_val;
                }
                iterator& operator--() { curr--; return *this; }
                iterator operator--(int)
                {
                    iterator return_val = *this;
                    --(*this);
                    return return_val;
                }
                
                bool operator==(const iterator& b) const
                {
                    return *curr == *b.curr;
                } 
                bool operator!=(const iterator& b) const
                {
                    return *curr != *b.curr
                }
                
                private:
                    pointer curr;
            };

            struct const_iterator
            {
                using value_type = T;
                using pointer = T*; 
                using reference = T&;

                const_iterator(pointer ptr) : m_ptr(ptr) {}

                pointer operator->() const { return m_ptr; }
                reference operator*() const {return m_ptr; }
                iterator& operator++ const { curr++; return *this; }
                iterator operator++ const (int)
                {
                    iterator return_val
                }

                private:
                    pointer curr;
            };

            struct reverse_iterator{

            };

            struct const_reverse_iterator{

            };

            /* construct/copy/destroy */
            vector();
            explicit vector(int s);
            vector(const vector& x);            // copy constructor
            const vector(vector&& x);
            const ~vector();
            vector& operator=(const vector& x); // copy assignment 

            // iterators
            iterator               begin();
            const_iterator         begin() const;
            iterator               end();
            const_iterator         end() const; 
            reverse_iterator       rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator       rend();
            const_reverse_iterator rend() const;
        
            const_iterator         cbegin() const;
            const_iterator         cend() const;
            const_reverse_iterator crbegin() const;
            const_reverse_iterator crend() const;

            // capacity
            bool empty() const;
            size_type size() const;         // Returns the number of elements in the vector
            size_type max_size() const;
            size_type capacity() const;
            void    resize(size_type sz);
            void    resize(size_type sz, const T& c);
            void    reserve(size_type n);
            void    shrink_to_fit();
            
            // element access
            reference           operator[](size_type n);
            const_reference     operator[](size_type n) const;
            reference           at(size_type n);
            reference           front();
            const_reference     front() const;
            reference           back();
            const_reference     back() const;

            // data access
            T*          data();
            const T*    data() const;

            // modifiers
            template<class... Args> reference emplace_back(Args&&... args);
            void push_back(const T& x);
            void push_back(T&& x);
            void pop_back();

            template<class... Args>
            constexpr iterator emplace(const_iterator position, Args&&... args);
            constexpr iterator insert(const_iterator position, const T& x);
            constexpr iterator insert(const_iterator position, T&& x);
            constexpr iterator insert(const_iterator position, size_type n, const T& x);
            template<class InputIt>
            constexpr iterator insert(const_iterator position,
                                        InputIt first, InputIt last);
            constexpr iterator insert(const_iterator position, initializer_list<T> il);
            constexpr iterator erase(const_iterator position);
            constexpr iterator erase(const_iterator first, const_iterator last);
            // constexpr void     swap(vector&)
            // noexcept(allocator_traits<Allocator>::propagate_on_container_swap::value ||
            //         allocator_traits<Allocator>::is_always_equal::value);
            constexpr void     clear();

    }; // end class vector
    
    /* BEGIN IMPLEMENTATION */

    // CONSTRUCTORS/DECONSTRUCTOR
    template<class T>
    vector<T>::vector(): space(0), size(0), arr(0) {}

    template<class T>
    vector<T>::vector(int s): size(s), arr(new T[s], space(s))
    {
        for(int i = 0; i < size; ++i){
            arr[i] = T();
        }
    }

    // copy constructor const
    template<class T>
    vector<T>::vector(const vector& arg): size(arg.size), elements(new T[arg.size])
    {
        for(int i = 0; i < arg.size; ++i){
            arr[i] = arg.elements[i];
        }
    }

    // template<class T>
    // const vector<T>::vector(vector&& arg)

    template<class T>
    vector<T>::~vector()
    { 
        delete[] arr;
    }


    // ITERATORS
    template<class T>
    vector<T>::iterator vector<T>::begin()
    {
        return vector<T>::iterator(&arr[0]);
    }

    template<class T>
    vector<T>::const_iterator vector<T>::cbegin() const
    {
        return vector<T>::const_iterator(&arr[0]);
    }

    template<class T>
    vector<T>::iterator vector<T>::end()
    {
        return vector<T>::iterator(&arr[size]);
    }

    template<class T>
    vector<T>::const_iterator vector<T>::cend() const
    {
        return vector<T>::const_iterator(&arr[size]);
    }


    // CAPACITY
    template<class T>
    bool vector<T>::empty() const
    {
        return (size == 0);
    }

    template<class T>
    vector<T>::size_type vector<T>::size() const
    {
        return size;
    }

    template<class T>
    vector<T>::size_type  vector<T>::max_size() const
    {
        return space;
    }

    template<class T>
    vector<T>::size_type  vector<T>::capacity() const
    {
        return space;
    }

    template<class T>
    void vector<T>::reserve(size_type newalloc)
    {

    }

    template<class T>
    vector<T>::size_type  vector<T>::capacity() const
    {
        return space;
    }

    template<class T>
    void vector<T>::resize(size_type sz)
    {

    }

    template<class T>
    void vector<T>::resize(size_type sz, const T& c)
    {

    }

    template<class T>
    void vector<T>::reserve(size_type n)
    {

    }

    template<class T>
    void vector<T>::shrink_to_fit()
    {

    }

    // ELEMENT ACCESS
    template<class T>
    vector<T>::reference vector<T>::operator[](size_type n)
    {

    }

    template<class T>
    vector<T>::const_reference vector<T>::operator[](size_type n) const
    {

    }

    template<class T>
    vector<T>::reference vector<T>::at(size_type n)
    {

    }

    template<class T>
    vector<T>::reference vector<T>::front()
    {
        return arr[0];
    }

    template<class T>
    vector<T>::const_reference vector<T>::front() const
    {

    }

    template<class T>
    vector<T>::reference vector<T>::back()
    {
        
    }

    template<class T>
    vector<T>::const_reference vector<T>::back() const
    {
        
    }

    template<class T>
    T* vector<T>::data()
    {
        return arr;
    }


    template<class T>
    const T* vector<T>::data() const
    {
        return arr;
    }
    
    
    // MODIFIERS
    template<class T>
    template<class... Args>
    vector<T>::reference vector<T>::emplace_back(Args&&... args){

    }

    template<class T>
    void vector<T>::push_back(const T& x)
    {
        
    }

    template<class T>
    void vector<T>::push_back(T&& x)
    {
        
    }

    template<class T>
    void vector<T>::pop_back()
    {
        
    }

    // END MODIFIERS

    template<class T>
    template<class... Args>
    constexpr vector<T>::iterator vector<T>::emplace(const_iterator position, Args&&... args){

    }

    template<class T>
    constexpr vector<T>::iterator vector<T>::insert(const_iterator position, const T& x){

    }

    template<class T>
    constexpr vector<T>::iterator vector<T>::insert(const_iterator position, T&& x){

    }

    template<class T>
    constexpr vector<T>::iterator vector<T>::insert(const_iterator position, size_type n, const T& x){

    }

    // template<class InputIt>
    // template<class T>
    // constexpr vector<T>::iterator vector<T>::insert(const_iterator position, InputIt first, InputIt last){

    // }

    // template<class T>
    // constexpr vector<T>::iterator vector<T>::insert(const_iterator position, initializer_list<T> il){

    // }

    template<class T>
    constexpr vector<T>::iterator vector<T>::erase(const_iterator position){

    }

    template<class T>
    constexpr vector<T>::iterator vector<T>::erase(const_iterator first, const_iterator last){

    }

    template<class T>
    constexpr void vector<T>::clear(){

    }

    
} // end namespace std