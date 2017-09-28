template<typename T>
class Handle
{
public:
	
	Node* node;
	
	Handle ()
	{
		node = (Node*)null_node;
	}
	
	Handle (Node* node)
	{
		this->node = node;
		node->Increase ();
	}
	
	Handle (Handle<T>& handle)
	{
		this->node = handle.node;
		node->Increase ();
	}
	
	Handle (const Handle<T>& handle)
	{
		
		this->node = handle.node;
		node->Increase ();
	}
	
	~Handle ()
	{
		this->node->Decrease ();
	}
	
	void Assign (Handle<T>& rval)
	{
		// Increase the count on the rval first,
		// if we (for instance) assign the Handle to itself,
		// We want to increase the node by 1 and THEN decrease it,
		// otherwise, it will decrease and delete itself
		// before we can increase it again.
		
		
		// Increase the rval node
		if (rval.node)
		{
			rval.node->Increase ();
		}
		
		
		// Decrease the current node
		if (node)
		{
			node->Decrease ();
		}
		
		
		// Assign the node
		node = rval.node;
	}
	
	Handle<T>& operator = (Handle<T>& rval)
	{
		// Assign the rval
		Assign (rval);
		
		// Return our self
		return *this;
	}
	
	Handle<T>& operator = (const Handle<T>& rval)
	{
		// Assign the rval
		Assign ((Handle<T>&)rval);
		
		// Return our self
		return *this;
	}
	
	T* operator () ()
	{
		if (node->master == 0x0)
		{
			return 0x0;
		}
		else
		{
			return (T*)node->master->object;
		}
	}
	
};