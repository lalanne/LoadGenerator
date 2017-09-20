
import subprocess


def test_no_server_up_1_1():
    args = ('../../load_generator', '1', '1', '../../test1.dat')
    popen = subprocess.Popen(args, stdout=subprocess.PIPE)
    popen.wait()

    output = popen.stdout.read()

    split_output = output.split('\n')
    result_split = split_output[2].split(' ')

    expected_result = 'connection fails'
    actual_result = result_split[2] + ' ' + result_split[3]

    expected_latency = '0'
    actual_latency = result_split[7]

    assert actual_result == expected_result
    assert actual_latency == expected_latency
