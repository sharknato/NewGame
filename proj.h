#pragma once

#include "proj.g.h"

namespace winrt::SFMLStuff::implementation
{
    struct proj : projT<proj>
    {
        proj();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::SFMLStuff::factory_implementation
{
    struct proj : projT<proj, implementation::proj>
    {
    };
}
