
import subprocess


def test_no_server_up_1_1():
    args = ('../../load_generator', '1', '1', '../../test1.dat')
    popen = subprocess.Popen(args, stdout=subprocess.PIPE)
    popen.wait()

    output = popen.stdout.read()

    split_output = output.split('\n')
    result_split = split_output[2].split(' ')

    assert result_split[2] == 'connection'
    assert result_split[3] == 'fails'
    assert result_split[5] == 'latency'
    assert result_split[7] == '0'
