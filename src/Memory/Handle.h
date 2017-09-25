template<typename T>
class Handle
{
public:
	
	Node* node;
	
	Handle ()
	{
		node = null_node;
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
	
	Handle<T>& operator = (Handle<T>& rval)
	{
		node->Decrease ();
		node = rval.node;
		node->Increase ();
		
		return *this;
	}
	
	Handle<T> operator = (Handle<T> rval)
	{
		(*this) = rval;
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