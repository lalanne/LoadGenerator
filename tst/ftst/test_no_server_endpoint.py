
import subprocess


class TestNoServerEndPoint(object):
    def test_clients_1_repetitions_1(self):
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

    def test_clients_2_repetitions_1(self):
        args = ('../../load_generator', '2', '1', '../../test1.dat')
        popen = subprocess.Popen(args, stdout=subprocess.PIPE)
        popen.wait()

        output = popen.stdout.read()

        split_output = output.split('\n')
        result_split_0 = split_output[2].split(' ')
        result_split_1 = split_output[3].split(' ')

        expected_result = 'connection fails'
        actual_result_0 = result_split_0[2] + ' ' + result_split_0[3]
        actual_result_1 = result_split_1[2] + ' ' + result_split_1[3]

        expected_latency = '0'
        actual_latency_0 = result_split_0[7]
        actual_latency_1 = result_split_1[7]

        assert actual_result_0 == expected_result
        assert actual_latency_0 == expected_latency
        assert actual_result_1 == expected_result
        assert actual_latency_1 == expected_latency
