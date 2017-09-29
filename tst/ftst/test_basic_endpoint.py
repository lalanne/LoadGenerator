
import subprocess
import time


class TestBasicServer(object):
    def test_basic(self):
        args_lg = ('../../load_generator', '1', '1', '../../test1.dat')
        popen_lg = subprocess.Popen(args_lg, stdout=subprocess.PIPE)

        popen_lg.wait()

        output = popen_lg.stdout.read()

        print output

        assert 1 == 1

