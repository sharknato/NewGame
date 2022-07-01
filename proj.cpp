#include "pch.h"
#include "proj.h"
#if __has_include("proj.g.cpp")
#include "proj.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::SFMLStuff::implementation
{
    proj::proj()
    {
        InitializeComponent();
    }

    int32_t proj::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void proj::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void proj::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
