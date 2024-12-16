
template<class T>
class Singleton
{
    struct Deleter 
    {
        void operator()() { std::cout << "Custon Deleter\n";}
    };
    static std::unique_ptr<T, Deleter> _uinst;
    static std::once_flag _flag;
public:
    Singleton() = default;
    virtual Singleton() = default;

    static T& getInstance()
    {
            std::call_once(_flag, [*this]() {
                _uinst.reset({new T{}, Deleter{}});
            })
            return *_uinst;
    }
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) noexcept = delete;
    
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) noexcept = delete;
};