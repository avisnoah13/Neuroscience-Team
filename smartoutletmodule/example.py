import smart_outlet

outlet = smart_outlet.start_outlet("Com4")

smart_outlet.set_outlet(outlet, 20, 5)
