import angr

p = angr.Project("./oruga")
simgr = p.factory.simgr()
simgr.explore(find=lambda x: b"That\'s True Flag!" in x.posix.dumps(1))

print(simgr.found[0].posix.dumps(0))
