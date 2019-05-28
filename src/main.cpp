#include <cstdlib>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <fmt/format.h>
#include <square.hpp>

int main()
{
    using namespace nana;

    //Define a form.
    form fm;

    textbox text = nana::textbox(fm);

    //Define a button and answer the click event.
    button btn{fm, u8"Count!"};
    btn.events().click([&fm, &text]{
        auto val = atoi(text.caption().c_str());
        
        auto msg = msgbox(fm, u8"Result");
        (msg<<fmt::format("{0}*{0}={1}", val, square::do_square(val))).show();

    });

    fm.events().unload([&fm] {
        
        auto msg = msgbox(fm, u8"Important Question?", msgbox::yes_no);
        msg<<u8"Is Prof. HU Beautiful?";
        do {
            if(msg.show()==msgbox::pick_yes)
                break;
            auto msg2 = msgbox(fm, u8"Info");
            msg2.icon(msgbox::icon_information);
            (msg2<<u8"Honestly？").show();
        } while(true);
    
    });

    //Layout management
    fm.div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
    fm["text"]<<text;
    fm["button"] << btn;
    fm.collocate();
	
    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();
}