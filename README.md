
1)  Declare a variable
~~~c
static uint8_t   heap[2048];  /*!< WHeap size for memory self allocator*/
~~~

2)  Init heap
~~~c
if(!heap_init(heap,sizeof(heap)))
    while(1); /*!< Bug catch tag*/
~~~

3)  Try to allocate memory 
~~~c   
Class_t* cthis = NULL;

if((cthis = heap_malloc_cast(Class_t)) == NULL)
    while(1); /*Bug catch tag*/     
~~~

or

~~~c
if((cthis = (Class_t*)heap_malloc(Class_t)) == NULL)
    while(1); /*Bug catch tag*/     
~~~        
    