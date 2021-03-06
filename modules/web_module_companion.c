/*
This module is the web panel companion
*/

int web_module_companion(void)
{
    //show the companion
    printf( "Welcome to the Team Eureka Companion" );
    printf( "</body> \n" );
    printf( "<script src=\"http://code.jquery.com/jquery-2.0.3.min.js\"></script> \n" );
    printf( "<script src=\"https://www.gstatic.com/cast/js/receiver/1.0/cast_receiver.js\"></script> \n" );
    printf( "<script src=\"messageTypes.js\"></script> \n" );
    printf( "<script> \n" );
    printf( "    $(function() { \n" );
    printf( "        var receiver = new cast.receiver.Receiver('TeamEurekaCompanion', ['TeamEurekaCompanion']), \n" );
    printf( "            channelHandler = new cast.receiver.ChannelHandler('TeamEurekaCompanion'), \n" );
    printf( "            $messages = $('.messages'); \n" );
    printf( " \n" );
    printf( "        channelHandler.addChannelFactory( \n" );
    printf( "            receiver.createChannelFactory('TeamEurekaCompanion')); \n" );
    printf( " \n" );
    printf( "        receiver.start(); \n" );
    printf( " \n" );
    printf( "        channelHandler.addEventListener(cast.receiver.Channel.EventType.MESSAGE, onMessage.bind(this)); \n" );
    printf( " \n" );
    printf( "        function onMessage(event) { \n" );
    printf( "            $messages.html(event.message.type); \n" );
    printf( "        } \n" );
    printf( "    }); \n" );
    printf( "</script> \n" );
}