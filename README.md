
1)  Declare a variable
~~~
static uint8_t   heap[2048];  /*!< WHeap size for memory self allocator*/
~~~

2)  Init heap
~~~
    if(!heap_init(heap,sizeof(heap)))
        while(1); /*!< Bug catch tag*/
~~~

3)  Try to allocate memory 
~~~    
    Class_t* cthis = NULL;
    
    if((cthis = heap_malloc_cast(Class_t)) == NULL)
        while(1); /*Bug catch tag*/     
~~~

    or

~~~
    if((cthis = (Class_t*)heap_malloc(Class_t)) == NULL)
        while(1); /*Bug catch tag*/     
~~~        
    