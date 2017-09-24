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
		node->master->Increase ();
	}
	
	Handle (Handle<T>& handle)
	{
		this->node = handle.node;
		node->master->Increase ();
	}
	
	Handle (const Handle<T>& handle)
	{
		
		this->node = handle.node;
		node->master->Increase ();
	}
	
	~Handle ()
	{
		this->node->master->Decrease ();
	}
	
	Handle<T>& operator = (Handle<T>& rval)
	{
		node->master->Decrease ();
		node = rval.node;
		node->master->Increase ();
		
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